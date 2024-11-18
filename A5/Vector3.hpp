#include "Vector.cpp"
using namespace std;

// class vector 3 inherits from class vector of size 3
class Vector3 : public Vector<3> {
public:
    
    // Default Constructor
    Vector3();

    // Copy Constructor
    Vector3(const Vector3& other);

    // Cross product function
    Vector3 cross(const Vector3& b);
};
