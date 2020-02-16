/* TOPIC: std::lock_guard In C++
 
NOTES:
0. It is very light weight wrapper for owning mutex on scoped basis.
1. It acquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard */

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
int buffer = 0;

void Task(const char* threadNumber, int loopFor)
{
    std::lock_guard<mutex> lock(m);
    for(int i=0 ; i<loopFor; i++)
    {
        buffer++;
        cout<<threadNumber<<buffer<<endl;
    }
}

int main()
{
    std::thread t1(Task,"T0", 5);
    std::thread t2(Task, "T1", 5);

    t1.join();
    t2.join();

    return 0;
}

//compile: g++ LockGuard.cpp -std=c++11 -pthrea
/* output:
T01
T02
T03
T04
T05
T16
T17
T18
T19
T110 */