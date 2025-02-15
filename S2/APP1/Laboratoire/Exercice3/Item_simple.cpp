#include "Item_simple.h"

#include <iostream>

using namespace std;
Item_simple::Item_simple(/* args */)
{
    cout << "Is::Is()" << endl;
}
Item_simple::Item_simple(int n)
{
    cout << "Is::Is(" << n << ")" << endl;
}

Item_simple::~Item_simple()
{
    cout << "Is::~Is()" << endl;
}