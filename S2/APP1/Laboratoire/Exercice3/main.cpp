#include "Item.h"
#include "Item_simple.h"
#include "Item_complexe.h"
#include <iostream>
using namespace std;

int main()
{
    Item it;
    Item_complexe* pitc;
    Item_complexe itcplx(10);
    cout << "0-----" << endl;
    it = Item(30);
    cout << "1-----" << endl;
    pitc = new Item_complexe();
    cout << "2-----" << endl;
    delete pitc;
    cout << "3-----" << endl;
    return 0;
}