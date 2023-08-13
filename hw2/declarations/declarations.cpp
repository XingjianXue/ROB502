// --- Your code here
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

std::string repeatString(std::string n, int m){
    std::string k;
    for (int i = 0; i < m; i++){
         k = k + n;
    }
return k;
}

double multiply(double m,double n){
   return m*n;
}

int negative_number;
double large_number,even_larger_number;
// ---

// include the standard library files that defines the std:: functions
int main() {
    // --- Your code here
    double some_number;
    std::string some_string;
    
    // ---
    
	// declare the variables used below
	some_number = 5.5;
    // std::endl and '\n' are equivalent
	std::cout << some_number << ' ' << std::round(some_number + M_PI) << '\n';

    // this one may be a bit tricky since you can't assign a string literal to char* in C++ 
	some_string = "my string";
	std::cout << some_string << '\n';

    // implement this function
    // should print empty string
    std::cout << repeatString(some_string, 0) << std::endl;
    // should print it 5 times, with nothing separating them
    std::cout << repeatString(some_string, 5) << std::endl;
	
	// there are many numerical types, each with different signedness and size
	// declare the appropriate types for them such that none of them overflow
    // note that 2^32 ~= 4 billion
    large_number = 1000000;
    large_number *= 3;
    std::cout << large_number << std::endl;

    even_larger_number = large_number * large_number;
    std::cout << even_larger_number << std::endl;

    // implement this multiply function
    std::cout << std::fixed << std::setprecision(1) << multiply(large_number, even_larger_number) << std::endl;

    // beware of numeric types' signedness
    negative_number = -250;
    std::cout << negative_number << std::endl;
}