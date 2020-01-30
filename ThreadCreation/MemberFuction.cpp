/*Thread creation using non static member function of class*/

#include<iostream>
#include<thread>


class Base
{
public:
    void PrintNumbers(int x)
    {
        while(x-->0)
            std::cout<<x<<std::endl;
    }
};

int main()
{
    Base b;
    std::thread t1(&Base::PrintNumbers,&b,10);

    t1.join();
    return 0;
}

/* Compile:g++ -std=c++11 MemberFuction.cpp -o MemberFuction.o -pthread*/