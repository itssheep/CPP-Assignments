#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Histogram
{
	public:
		Histogram(std::vector<double> endpoints);

		// Copy constructor
		Histogram(const Histogram& other);

		// Move constructor
		Histogram(Histogram&& other);

		// Destructor
		~Histogram() {clear();}

		// Clear Histogram Statistics and Data
		void clear();

		// Add a new value to the histogram
		bool update(double newvalue);

		// Copy assignment operator
		Histogram& operator=(Histogram& other);

		// Move assignment operator
		Histogram& operator=(Histogram&& other);

		// Overloaded addition operator
		Histogram operator+(Histogram other);

		void display(ostream& os)
		{
		        if (endpoints.size() > 0)
		        {
		                cout << setfill(' ') << right << fixed << showpoint << setprecision(2);
		                for (int i = 0; i < endpoints.size()-1; i++)
		                {
		                        os << "[" << setw(5) << right << endpoints[i] << ", " << setw(5) << left << endpoints[i+1] << ")" << "\t";
		                        for (int j = 0; j < numberinbin[i]; j++)
		                        {
		                                os << "*";
		                        }
		                        os << endl;
		                }
		        }
		}

	private:
		vector<double> endpoints;
		vector<double> values;
		vector<int> numberinbin;
};
