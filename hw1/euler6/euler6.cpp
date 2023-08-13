#include <iostream>

int main() {
    // --- Your code here
    int difference = 0; int sum1 = 0; int sum2 = 0;
    for (int i = 1; i <= 100; i++){
        sum1 = i*i + sum1;
        sum2 = i + sum2;
    }
    difference = sum2*sum2 - sum1;
    // ---
    std::cout << difference << std::endl;
    return 0;
}
