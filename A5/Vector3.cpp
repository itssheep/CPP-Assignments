// Using header file (Vector3.hpp) implement methods for 3D vectors.
// This is my implementation

#include "Vector3.hpp"
using namespace std;

// default constructor of Vector3 is just a Vector of size 3
Vector3::Vector3() : Vector<3>() {}

// copy constructor is just the copy of a 3D Vector
Vector3::Vector3(const Vector3& other) : Vector<3>(other) {}

// cross product implementation with 2 vectors, a and b.
Vector3 Vector3::cross(const Vector3& b) {
    Vector3 newVec;
    
    // basically we are using Vector set and get components to perform cross product on each individual entry
    newVec.setComponent(0, getComponent(1) * b.getComponent(2) - getComponent(2) * b.getComponent(1));
    newVec.setComponent(1, getComponent(2) * b.getComponent(0) - getComponent(0) * b.getComponent(2));
    newVec.setComponent(2, getComponent(0) * b.getComponent(1) - getComponent(1) * b.getComponent(0));
    
    return newVec;
}


