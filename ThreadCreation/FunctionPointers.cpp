/* Function pointres  
This is very basic type of thread creation
Program: print numbers 
*/

#include<iostream>
#include<thread>
#include<algorithm>

using namespace std;

void PrintNumbers(int x)
{
    while(x-- >0 )
    {
        std::cout<<x<<std::endl;
    }
}

int main()
{
    std::thread t1(PrintNumbers, 10);
    t1.join();
    return 0;
}

/*Compile: g++ -std=c++17 FunctionPointers.cpp -o FunctionPointers.o -pthread

*/