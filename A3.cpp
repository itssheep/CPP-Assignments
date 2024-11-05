#include "Histogram.hpp"

Histogram::Histogram(std::vector<double> endpoints){
    this->endpoints = endpoints;
    numberinbin.resize(endpoints.size()-1);
    }
    // Initializes the object and assigns it the given vector of endpoints
Histogram::Histogram(const Histogram& other){
    endpoints=other.endpoints;
    values=other.values;
    numberinbin=other.numberinbin;
}
//Copy Constructor
Histogram::Histogram(Histogram&& other){
    this->endpoints=move(other.endpoints);
    this->values=move(other.values);
    this->numberinbin=move(other.numberinbin);
}
//Move Constructor

void Histogram::clear(){
    numberinbin.clear();
    values.clear();
    endpoints.clear();
}
//Clear function that resets all the vectors of an object when called

bool Histogram::update(double newvalue){
    if(newvalue<endpoints[0]||newvalue>=endpoints[(endpoints.size())-1]){
        return false;
    }
    for (int i=1;i<endpoints.size();i++){
        if(newvalue<endpoints[i]){
            numberinbin[i-1]+=1;
            values.push_back(newvalue);
            return true;
        } 
    }
}
/*Used to take a value and sort it by adjusting the numberinbin vector.
First it checks that the value falls within the range of the endpoints,
then sorts it based on the range it falls into.*/

Histogram& Histogram::operator=(Histogram& other){
    if (this != &other){
        endpoints=other.endpoints;
        values=other.values;
        numberinbin=other.numberinbin;
    }
    return *this;
}
//copy assignment operator

Histogram& Histogram::operator=(Histogram&& other){
    if (this != &other){
        endpoints=move(other.endpoints);
        values=move(other.values);
        numberinbin=move(other.numberinbin);
    }
    return *this;

}
//move assignment operator

Histogram Histogram::operator+(Histogram other){
    sort(other.endpoints.begin(),other.endpoints.end());
    
    vector<double> result;
    result.reserve(endpoints.size()+ other.endpoints.size());
    set_union(endpoints.begin(),endpoints.end(),other.endpoints.begin(),other.endpoints.end(),back_inserter(result));
    /*Creates a new vector "result" to hold the values of the combineded endpoints.
    Uses set_union to combine these two vectors removing duplicates*/

    vector<double> newValues;
    newValues.reserve(values.size()+other.values.size());
    newValues.insert(newValues.end(),other.values.begin(),other.values.end());
    newValues.insert(newValues.end(),values.begin(),values.end());
    /*Creates a new vector which is a combination of the two vectors of values*/

    Histogram myHistogram(result);
    myHistogram.values=newValues;
    //Creates a new object of class Histogram named "myHistogram"
    for (int i=0;i<newValues.size();i++){
        myHistogram.update(newValues[i]);
    }
    //Iterates through the vector of values and calls the update method to adjust the numberinbin total
    return myHistogram;
    }



    
    

