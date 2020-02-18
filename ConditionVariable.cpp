/* TOPIC: Condition Variable In C++ Threading

NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition */

#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

using namespace std;

long balance = 0;
std::condition_variable cv;
std::mutex m;

void AddMoney(const int & money)
{
    std::lock_guard<mutex> lg(m);
    balance+=money;
    cout<<"Amount added current balance " <<balance<<endl;
    cv.notify_one();
}

void WithdrawMoney(const int & money)
{
    std::unique_lock<mutex> ul(m);
    cv.wait(ul,[]{return (balance!=0)?true:false;});
    if(balance>=money)
    {
        balance-=money;
        cout<<"Ammount deducted "<<money<<endl;
    }
    else
    {
        cout<<"Ammount cant be deducted balance is less than "<<money<<endl;
    }
    cout<<"Current balance is "<<balance<<endl;
}

int main()
{
    std::thread t1(WithdrawMoney, 500);
    std::thread t2(AddMoney, 500);

    t1.join();
    t2.join();

    return 0;
}

// Compile: g++ ConditionVariable.cpp -std=c++11 -pthread
/* output:
Amount added current balance 500
Ammount deducted 500
Current balance is 0 */