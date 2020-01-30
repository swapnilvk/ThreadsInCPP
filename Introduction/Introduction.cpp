/* TOPIC: Introduction to thread in c++ (c++11)

QUESTIONS
1. What do you understand by thread and give one example in C++?

ANSWER
0. In every application there is a default thread which is main(), in side this we create other threads.
1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
   For example:
   (a) The browser has multiple tabs that can be different threads. 
   (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
   (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

WAYS TO CREATE THREADS IN C++11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions */

#include <iostream>
#include<thread>
#include<algorithm>
#include<chrono> //clock
typedef unsigned long long int ull;

using namespace std;
using namespace std::chrono;

ull EvenSum = 0;
ull OddSum = 0;

void FindEvenSum(ull start, ull end)
{
    for (ull i = start; i <=end; i++)
    {
        if(i%2 == 0 )
           EvenSum += i;
    }
}

void FindOddSum(ull start, ull end)
{
    for (ull i = start; i <=end; i++)
    {
        if(i%2 != 0 )
           OddSum += i;
    }
}

int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();
/* 
    FindEvenSum(start, end);
    FindOddSum(start, end); */

    std::thread t1(FindEvenSum, start, end);
    std::thread t2(FindOddSum, start, end);

    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout<<"Even sum = "<< EvenSum<<endl;
    cout<<"Odd sum = "<<OddSum<<endl;
    cout<<"Duration in seconds = "<<duration.count()/1000000<<endl;

    return 0;
}
