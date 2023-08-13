#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>

int main()
{
    double a, b, c;
    std::cout << "Type in a, b, and c. Press 'Enter' between each\n";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cout << std::setprecision(4);
    // --- Your code here
    double delta = sqrt(pow(b,2) - 4*a*c);
    if (delta > 0){
       std::cout << (-b - delta)/(2*a) << std::endl;
       std::cout << (-b + delta)/(2*a) << std::endl;
    }
    else if (delta == 0 && b!= 0){
        std::cout << (-b)/(2*a) << std::endl;
    }
    else if (delta == 0 && b == 0){
        std::cout << b/(2*a) << std::endl;
    }
    else{
        std::cout << "None" << std::endl;
    }

    // ---
    return 0;
}
