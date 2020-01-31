/* TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

Mutex: Mutual Exclusion

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition. */

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;

int myMoney = 0;

void AddMoney()
{
    m.lock();
    myMoney++;
    m.unlock();
}

int main()
{
    std::thread t1(AddMoney);
    std::thread t2(AddMoney);

    if(t1.joinable())
        t1.join();
    
    if(t2.joinable())
        t2.join();
    cout<<myMoney<<endl;
    return 0;
}

// compile: g++ -std=c++11 Mutex.cpp -pthread