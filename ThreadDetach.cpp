/* DETACH NOTES
0. This is used to detach newly created thread from the parent thread.
1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
   double detach() will result into program termination.
2. If we have detached thread and main function is returning then the detached thread execution is suspended */

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void PrintNumbers(int x)
{
    while(x-->0)
        cout<<" Swapnil "<<x<<endl;

    //std::this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
    std::thread t1(PrintNumbers, 10);
    cout<<"main thread"<<endl;
    
    if(t1.joinable())
        t1.detach();

    cout<<"main after completion of thread"<<endl;

    return 0;
}

// compile: g++ -std=c++11 ThreadDetach.cpp -pthread