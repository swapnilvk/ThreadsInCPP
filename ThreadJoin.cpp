/* JOIN NOTES
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
1. Double join will result into program termination.
2. If needed we should check thread is joinable before joining. ( using joinable() function) */

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void PrintNumbers(int x)
{
    while(x-->0)
        cout<<"Swapnil "<<x<<endl;

    std::this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
    std::thread t1(PrintNumbers, 10);
    cout<<"main thread"<<endl;
    
    if(t1.joinable())
        t1.join();

cout<<"main after completion of thread"<<endl;

    return 0;
}

// compile: g++ -std=c++11 ThreadJoin.cpp -pthread