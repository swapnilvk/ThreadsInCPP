/* 
TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)

NOTES:
0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
   otherwise false.
1. Member Function:
   a. lock 
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex.
   d. try_lock_until  ---/ 
   e. unlock

EXAMPLE: try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns fals */

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

int myAmmount = 0;
std::timed_mutex m;

void Increament(int i)
{
    if(m.try_lock_for(std::chrono::seconds(1)))
    {
        ++myAmmount;
        std::this_thread::sleep_for(chrono::seconds(2));
        cout<<"Thread "<<i <<" Entered"<<endl;
        m.unlock();
    }
    else
    {
        cout<<"Thread "<<i<<" could not enter"<<endl;
    }
}

int main()
{
    std::thread t1(Increament, 1);
    std::thread t2(Increament, 2);

    t1.join();
    t2.join();

    cout<<"Myammount = "<<myAmmount<<endl;
}

//Compile: g++ TimedMutex.cpp -std=c++11 -pthread 


/*Output:
Thread 2 could not enter
Thread 1 Entered
Myammount = 1 */