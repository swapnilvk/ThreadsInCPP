// DeadLock With Example In C++
#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
std::mutex m1;
std::mutex m2;

using namespace std;

void Thread1()
{
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    m2.lock();
    cout<<"Critical section of Thread 1"<<endl;
    m1.unlock();
    m2.unlock();
}

void Thread2()
{
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m1.lock();
    cout<<"Critical section of Thread 2"<<endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    t1.join();
    t2.join();

    return 0;
}

// compile : g++ DeadLock.cpp -std=c++11 -pthread