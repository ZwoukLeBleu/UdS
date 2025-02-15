#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(){
	cout << "It::It()" << endl;
}


Item::Item(int n){
	cout << "It::It(" << n << ")" << endl;
}


Item::~Item(){
	cout << "It::~It()" << endl;
}
