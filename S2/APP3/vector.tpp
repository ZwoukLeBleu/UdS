#include "vector.h"
#include <iostream>

using namespace std;

template <typename T>
void Vector<T>::double_capacity()
{
    m_capacity *= 2;
    // cout << "Doubling capacity" << endl;
    // cout << "New capacity: " << m_capacity << endl << endl;
    T *new_data = new T[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;

}

template <typename T>
Vector<T>::Vector()
{
    m_size = 0;
    m_capacity = 2;
    data = new T[m_capacity];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(T value){
        this->push_back(value); 
        cout << "Adding value: " << this->at(m_size-1) << " to index " << this->size()-1 << endl; // DEBUG
        return *this;
}

template <typename T>
T& Vector<T>::operator[](unsigned int index){
    cout << "Getting value: " << data[index] << " from index " << index << endl; // DEBUG
    return data[index];
}

// TODO : this works but i dont understand why
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "[";
    for (unsigned int i = 0; i < vec.m_size; ++i) {
        os << vec.data[i];
        if (i < vec.m_size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}




template <typename T>
unsigned int Vector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
unsigned int Vector<T>::size()
{
    return m_size;
}

template <typename T>
T Vector<T>::at(unsigned int index){
    if (index > m_size) {cerr << "ERROR in function .at() [Index out of bounds]" << endl; return 0;}
    else { return data[index]; }

    
}

template <typename T>
void Vector<T>::push_back(T value)
{
    if (m_size == m_capacity) { double_capacity(); }
    data[m_size] = value;
    m_size++;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0) { m_size--; }
    else {cerr << "ERROR in function .pop_back() [No more items to remove]" << endl;}
}

template <typename T>
void Vector<T>::insert(unsigned int index, T value){
    if (m_size == m_capacity) { double_capacity(); }
    for (int i=m_size; i>index; i--){
        data[i] = data[i-1];
    }
    data[index] = value;
    m_size++;
}

template <typename T>
void Vector<T>::erase(unsigned int index){
    if (index >= m_size) {cerr << "ERROR in function .erase() [Index out of bounds]" << endl; return;}
    else {
        for (int i=index; i<m_size-1; i++){
            data[i] = data[i+1];
        }
        m_size--;

    }
}

template <typename T>
void Vector<T>::replace(unsigned int index, T value){
    if (index >= m_size) {cerr << "ERROR in function .replace() [Index out of bounds]" << endl; return;}
    else {
    data[index] = value;
    }
}

template <typename T>
void Vector<T>::reset(){
    m_size = 0;
}


