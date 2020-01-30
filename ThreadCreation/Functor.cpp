/*Thread creation using Functors (function objects)*/

#include<iostream>
#include<thread>


class Base
{
public:
    void operator()(int x)
    {
        while(x-->0)
            std::cout<<x<<std::endl;
    }
};

int main()
{
    std::thread t1(Base(),10);

    t1.join();
    return 0;
}

/* Compile:g++ -std=c++11 Functor.cpp -o Functor.o -pthread*/