#include "vector.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    Vector<float> v;

    v+=1.1;
    v+=2.2;
    v+=3.3;
    v+=4.4;
    v+=5.5;
    // cout << v.at(0) << endl;
    // cout << v.at(1) << endl;
    // cout << v.at(2) << endl;
    // v.erase(1);
    v[0] = 0.1;
    v[1] = 0.2;
    v[2] = 0.3;
    v[3] = 0.4;
    v[4] = 0.5;

    cout << v << endl;
    ofstream file("vector.txt");
    file << v;
    // v+=2.2;

    // cout << "Out : " << v.at(0) << endl;
    // cout << "Out : " << v.at(1) << endl;
    // cout << "Out : " << v.at(2) << endl;
    // cout << "Out : " << v.at(3) << endl;
    // cout << "Out : " << v.at(4) << endl;
    // cout << "Size: " << v.size() << endl;
    // cout << "Capacity: " << v.capacity() << endl;

    // v.pop_back();
    // v.push_back(1.1);
    // v.push_back(2.2);
    // v.push_back(3.3);
    // v.push_back(4.4);
    // v.push_back(5.5);

    // v.pop_back();
    // cout << v.at(9) << endl;


    // cout <<  v.at(0) << endl;
    // cout << "Size: " << v.size() << endl;
    // cout << "Capacity: " << v.capacity() << endl;
    return 0;

}