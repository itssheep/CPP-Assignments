// GIVEN HEADER FILE, NOT MINE

#include <iostream>

template <typename T>
class Point2 {
    public:

    typedef T Coordinate;

    // Default constructor with x = 0 and y = 0
    Point2();
    
    // Constructor with x = given input and y = given input
    Point2(const T& x, const T& y);

    // reference to X point
    T& x();
    
    const T& x() const;

    // reference to y point
    T& y();

    const T& y() const;
    
    // overloaded plus operator
    Point2& operator+=(const Point2& p);
    
    //overloaded minus operator
    Point2& operator-=(const Point2& p);

    private:
    T x_;
    T y_;
};

// overloaded << operator for printing to terminal
template <typename T>
std::ostream& operator<<(std::ostream& out, const Point2<T>& p);

// overloaded >> operator for taking input
template <typename T>
std::istream& operator>>(std::istream& in, const Point2<T>& p);
