#include "Item_complexe.h"
//#include "Item_simple.h"
#include <iostream>

using namespace std;

Item_complexe::Item_complexe(/* args */)
{
    cout << "Ic::Ic()" << endl;
}

Item_complexe::Item_complexe(int n)
{
    cout << "Ic::Ic(" << n << ")" << endl;
}

Item_complexe::~Item_complexe()
{
    cout << "Ic::~Ic()" << endl;
}

