#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>

using namespace std;

template<class I, typename T>
auto for_every(I input, function<void(T)> do_this)
{
    for_each(begin(input), end(input), do_this);
}

//function<void(string)> print_each = [](string name)->void {
//    cout << name << endl;
//};
//for_every(names, print_each);


class Vehicle
{
public:
    Vehicle() = delete;
    Vehicle(const Vehicle&) = delete;
    Vehicle(int wheels, string type):name(type),wheels(wheels) {
        
    }
private:
    string name = "unknown";
    int wheels = 0;
};

void Initialization()
{
    Vehicle car{ 4,"car" };

    //auto car2 = car;
    //auto truck = new Vehicle();

    auto truck = make_unique<Vehicle>(18, "18 wheeler");

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

void LambdaYCombinatorFib(int pos)
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
    auto C = 0;
    vector<int> range = { C++,C++,C++,C++,C++,C++,C++,C++,C++,C++,C++ };

    for (auto i : range)
    {
        LambdaYCombinatorFib(i);
    }

    Initialization();

    vector<string> names = { "Jonas", "Maciek", "Leo" };

    auto first = begin(names);
    auto last = end(names);

    cout << "Hello " << [names]() {return names[2]; }() << endl;
    
    for_each(first, last, [](auto name) {
        cout << name << endl;
    });


    cout << "names has " << count(names) << " names" << endl;
}

