/*Thread creation using labda expression*/

#include<iostream>
#include<thread>

auto LPrintNumbers = [](int x){
    while(x-->0)
        std::cout<<x<<std::endl;
};

int main()
{
    std::thread t1(LPrintNumbers,10);

    //We can directly pass labda expression to thread 
    std::thread t2([](int x){
    while(x-->0)
        std::cout<<x<<std::endl;
},10);
    t1.join();
    t2.join();

    return 0;
}

/* Compile:
g++ -std=c++11 LambdaExpression.cpp -o LambdaExpression.o -pthread */