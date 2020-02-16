/* TOPIC: Recursive Mutex In C++ (std::recursive_mutex)
 
NOTES:
0. It is same as mutex but, Same thread can lock one mutex multiple times using recursive_mutex.
1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now 
   as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
2. But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock
   it 10 times otherwise no other thread will be able to lock mutex m1.
   It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
3. How many time we can lock recursive_mutex is not defined but when that number reaches and if we were calling
   lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

BOTTOM LINE:
0. It is similar to mutex but have extra facility that it can be locked multiple time by same thread.
1. If we can avoid recursive_mutex then we should because it brings overhead to the system.
2. It can be used in loops also. */

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::recursive_mutex m;
int buffer = 0;

void Reccuresion(char c, int loopFor)
{
    if(loopFor<0)
        return;
    
    m.lock();
    cout<<"Lock by thread "<<c<<" "<<buffer++<<endl;
    Reccuresion(c,--loopFor);
    m.unlock();
    cout<<"Unlock by thread "<<c<<endl;
}

int main()
{
    std::thread t1(Reccuresion, '1', 10);
    std::thread t2(Reccuresion, '2', 10);
    
    t1.join();
    t2.join();

    return 0;
}
//Compile :g++ RecursiveMutex.cpp -std=c++11 -pthread
/* Output:
Lock by thread 1 0
Lock by thread 1 1
Lock by thread 1 2
Lock by thread 1 3
Lock by thread 1 4
Lock by thread 1 5
Lock by thread 1 6
Lock by thread 1 7
Lock by thread 1 8
Lock by thread 1 9
Lock by thread 1 10
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Unlock by thread 1
Lock by thread 2 11
Lock by thread 2 12
Lock by thread 2 13
Lock by thread 2 14
Lock by thread 2 15
Lock by thread 2 16
Lock by thread 2 17
Lock by thread 2 18
Lock by thread 2 19
Lock by thread 2 20
Lock by thread 2 21
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
Unlock by thread 2
*/