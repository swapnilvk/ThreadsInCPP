
/* TOPIC: unique_lock In C++

NOTES:
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. (See this in coming videos)

Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  do not acquire ownership of the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex */

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;
int buffer = 0;

void Task(const char* threadNumber, int loopFor)
{
    std::unique_lock<mutex> lock(m,std::defer_lock);
    lock.lock();
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

/* compile : g++ UniqueLock.cpp -std=c++11 -pthread */
/* Output:
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