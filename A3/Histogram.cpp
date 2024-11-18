#include "Histogram.hpp"
using namespace std;


// Initialize Histogram with given endpoints.
Histogram::Histogram(vector<double> endpoints) {
    this->endpoints = endpoints;
    numberinbin.resize(endpoints.size() - 1); // Resize bins based on # of endpoints
}


// Copy constructor
Histogram::Histogram(const Histogram& other) {
    endpoints = other.endpoints;
    values = other.values;
    numberinbin = other.numberinbin;
}


// Move constructor
Histogram::Histogram(Histogram&& other) {
    endpoints = move(other.endpoints);
    values = move(other.values);
    numberinbin = move(other.numberinbin);
}


// Clear all data in Histogram.
void Histogram::clear() {
    numberinbin.clear(), values.clear(), endpoints.clear();
}


// Update Histogram with new values.
bool Histogram::update(double val) {

    // Check if value is within range of endpoints.
    if(endpoints[0] > val || val >= endpoints[endpoints.size() - 1]) {
        return false;
    }

    // Find correct bin for new value
    for (int i = 1; i <= endpoints.size(); i++) {
        if(endpoints[i] > val) {
            numberinbin[i-1]+= 1;
            values.push_back(val);

            return true;
        } 
    }
}

// Copy assignment
Histogram& Histogram::operator=(Histogram& other) {

    // Check if its self-assigned
    if (this != &other) {
        endpoints = other.endpoints;
        values = other.values;
        numberinbin = other.numberinbin;
    }

    return *this;
}


// Move assignment
Histogram& Histogram::operator=(Histogram&& other) {

    // Check if self assigned.
    if (this != &other) {
        endpoints = move(other.endpoints);
        values = move(other.values);
        numberinbin = move(other.numberinbin);
    }

    return *this;

}


// Overloaded addition Operator
Histogram Histogram::operator+(Histogram other) {

    // First sort the endpoints of the other histogram
    sort(other.endpoints.begin(), other.endpoints.end());

    // Combine endpoints into a result vector
    vector<double> result;

    result.reserve(endpoints.size() + other.endpoints.size());
    set_union(endpoints.begin(), endpoints.end(), other.endpoints.begin(), other.endpoints.end(), back_inserter(result));

    // Combine values from both histograms
    vector<double> combinedValues = values; 

    combinedValues.insert(combinedValues.end(), other.values.begin(), other.values.end());

    // Create the new histogram and update it with the combined values
    Histogram myHistogram(result);

    // Update new histogram with new values.
    for (int i = 0; i < combinedValues.size(); i++) {
        myHistogram.update(combinedValues[i]);
    }

    return myHistogram;
}
