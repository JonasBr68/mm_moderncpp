#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstdio>
#include <iterator>

using namespace std;

template<class I, typename T>
auto for_every(I input, function<void(T)> do_this)
{
    for_each(begin(input), end(input), do_this);
}


struct SillyStruct
{
    int first;
    int second;
    string label;
};

class Vehicle
{
public:
    Vehicle() = delete; //No default constructor emitted by the compiler
    Vehicle(const Vehicle&) = delete; //No default copy constructor emitted by the compiler
    Vehicle(int wheels, string type):
        name(type),
        wheels(wheels),
        struct1{} {    
    }

private:
    string name = "unknown"; //Now possible in declaration
    int wheels{}; // 0 initialized

    //values in list matches order of struct members
    SillyStruct struct1 {1,2,"silly"}; 

    SillyStruct struct2; //No initialization, random memory
    SillyStruct struct3 {}; // 0 Initialized
};

void Initialization()
{
    Vehicle car{ 4,"car" }; //Matches up with constructor arguments

    //auto car2 = car;
    //auto truck = new Vehicle();

    //unique_ptr
    auto truck = make_unique<Vehicle>(18, "18 wheeler");

    //move semantics
    auto truck2 = move(truck);

    cout << "truck is null? " << boolalpha << (truck.get() == nullptr) << endl;
    cout << "truck2 is null? " << boolalpha << (truck2.get() == nullptr) << endl;
}

template<typename T>
auto count(T input) -> int
{
    int i = 0;
    for_each(begin(input), end(input), [&i](auto every)
    {
        i++;
    });
    return i;
}
template<typename T>
auto countArray(T input) -> int
{
    int i = 0;
    for(auto e : input)
    {
        i++;
    };
    return i;
}

template<typename T>
void LambdaYCombinatorFib(T pos)
{

    ([](auto f, auto n) {
        cout << "fibbonachi position " << n << " = " << f(f, n) << endl;
    })(
        [](auto f, auto i) -> int
    {
        return (i < 2u) ? i : (f(f, i - 1) + f(f, i - 2));
    },
        pos);

}

int main()
{
    //auto
    auto C = 0;
    vector<int> range = { C++,C++,C++,C++,C++,C++,C++,C++,C++,C++,C++ };

    //range based for
    for (auto i : range)
    {
        //Outputs the fibbonachi number for position i
        LambdaYCombinatorFib(i);
    }

    vector<string> names = { "Enrique", "Jonas", "Maciek", "Leo" };
    for (auto n : names){
        cout << n << endl;
    }


    Initialization();


    //lambdas

    //silly lambda
    cout << "Hello " << [names]() {return names[2]; }() << endl;

    auto first = begin(names);
    auto last = end(names);

    for_each(first, last, [](auto name) {
        cout << name << endl;
    });


    cout << "names has " << count(names) << " names" << endl;
    cout << "range has " << count(range) << " elements" << endl;


    int elements[10] = {9,8,7,6,5,4,3,2,1,0};

    for_each(begin(elements), end(elements), [](auto every)
    {
        cout << every << endl;
    });

    // cout << "elements has " << count(elements) << " elements" << endl;
    // cout << "elements has " << countArray(elements) << " elements" << endl;


    getchar();
}

