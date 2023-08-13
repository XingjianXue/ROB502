// --- Your code here
#include <iostream>
#include <iomanip>
double mi_to_km(double mi){
    double km = mi * 1.609;
    return km;
}
int main(){
    double x;
    std::cin >> x;
    double km = mi_to_km(x);
    std::cout << std::setprecision(3) << km << std::endl;
    return 0;
}


// ---
