#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    // determines volume of a cone (2 args from stdin) 
    // again, you should create the variable `volume` for the output.
    double radius, height;
    std::cout << "Enter the radius and height on separate lines\n";
    std::cin >> radius;
    std::cin >> height;
    // --- Your code here
    double volume = 1.0/3 * height * pow(radius, 2) * M_PI;
    // ---
    std::cout << std::setprecision(3) << volume << std::endl;
    return 0;
}
