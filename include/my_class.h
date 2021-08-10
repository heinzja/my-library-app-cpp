#ifndef MY_CLASS_H_INCLUDED
#define MY_CLASS_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class MyClass
{
public:
   MyClass(); // Constructor
   int add(int a, int b);

private:
   std::string name;
};

#endif
