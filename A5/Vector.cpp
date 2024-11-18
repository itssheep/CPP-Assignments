#include "Vector.hpp"
#include <iostream>
#include <vector>
using namespace std;

// default constructor, set all components to 0
template <size_t N>
Vector<N>::Vector() : components{}, numcomponents(N) {}

// copy constructor
template <size_t N>
Vector<N>::Vector(const Vector<N>& other) {
    numcomponents = other.numcomponents;
    components[numcomponents];
    for (int i = 0; i < numcomponents; i++) {
        components[i] = other.components[i];
    }
}

// dot product
template <size_t N>
float Vector<N>::dot(Vector<N> v) const {
    float result = 0.0f;
    for (int i = 0; i < numcomponents; i++) {
        result += (components[i] * v.components[i]);
    }
    return result;
}

// magnitude of vector
template <size_t N>
float Vector<N>::magnitude() const {
    float sum = 0.0f;
    for (int i = 0; i < numcomponents; i++) {
        sum += (components[i] * components[i]);
    }
    return sqrt(sum);
}

// get component of ith place
template <size_t N>
float Vector<N>::getComponent(int i) const {
    if (i < 0 || i >= numcomponents) {
        return -1;
    }
    else {
        return components[i];
    }
}

// set component of ith place
template <size_t N>
bool Vector<N>::setComponent(int i, float value) {
    if (i < 0 || i >= numcomponents) {
        return false;
    }
    else {
        components[i] = value;
        return true;
    }
}

// overloaded + operator
template <size_t N>
Vector<N> Vector<N>::operator+(const Vector<N> &other) const {
    Vector<N> newVec;
    for (int i = 0; i < numcomponents; i++) {
        newVec.components[i] = other.components[i] + components[i];
    }
    return newVec;

}

// overloaded - operator
template <size_t N>
Vector<N> Vector<N>::operator-(const Vector<N> &other) const {
    Vector<N> newVec;
    for (int i = 0; i < numcomponents; i++) {
        newVec.components[i] = components[i] - other.components[i];
    }
    return newVec;
}
