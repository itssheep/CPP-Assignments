// Using given header file, convert the class into a template class and create the methods
// This is my implementation

#include <iostream>
#include "Point2.h"

template <typename T>
// Default constructor with x = 0 and y = 0
Point2<T>::Point2() : x_(0), y_(0) {}

template <typename T>
// Constructor with x = given input and y = given input
Point2<T>::Point2(const T& x, const T& y) : x_(x), y_(y) {}

template <typename T>
// reference to X point
T& Point2<T>::x() {
    return x_;
}

template <typename T>
const T& Point2<T>::x() const {
    return x_;
}

template <typename T>
// reference to y point
T& Point2<T>::y() {
    return y_;
}

template <typename T>
const T& Point2<T>::y() const {
    return y_;
}

template <typename T>
// overloaded plus operator
Point2<T>& Point2<T>::operator+=(const Point2& p) {
    x_ += p.x();
    y_ += p.y();
    return *this;
}

template <typename T>
//overloaded minus operator
Point2<T>& Point2<T>::operator-=(const Point2& p) {
    x_ -= p.x();
    y_ -= p.y();
    return *this;
}


// overloaded << operator for printing to terminal
template <typename T>
std::ostream& operator<<(std::ostream& out, const Point2<T>& p) {

    out << "(" << p.x() << ", " << p.y() << ")" << std::endl;
    return out;
}

// overloaded >> operator for taking input
template <typename T>
std::istream& operator>>(std::istream& in, const Point2<T>& p) {
    in >> p.x_ >> p.y_;
    return in;
}

