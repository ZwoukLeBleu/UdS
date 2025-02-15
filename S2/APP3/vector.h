#pragma once

#include <iostream>
using namespace std;


template <typename T>
class Vector
{
private:
    T *data;
    unsigned int m_capacity;
    unsigned int m_size;

public:
    Vector(/* args */);
    ~Vector();

    Vector<T>& operator+=(T value);
    T& operator[](unsigned int index);

    // TODO : this works but i dont understand why
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec); 

    void double_capacity();
    unsigned int capacity();
    unsigned int size();
    T at(unsigned int index);

    void push_back(T value);
    void pop_back();
    void insert(unsigned int index, T value);
    void erase(unsigned int index);
    void replace(unsigned int index, T value);   
    void reset();
    
    
};

#include "vector.tpp"
