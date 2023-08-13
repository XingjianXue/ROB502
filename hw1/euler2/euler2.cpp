#include <iostream>
#include <string>
int x = 1; int y = 2; int n = 0; int sum = y; 
int main() {
    // you'll need to store the answer in a variable named 'sum'
    // --- Your code here
    //int x = 1; int y = 2; int n = 0; int sum = y; 
    while (n < 4000000){
       n = x + y;
             if (n % 2 == 0){
             sum = sum + n;
            }
       x = y;
       y = n;
    }   
    std::cout << sum << std::endl;
    // ---
    return 0;
}
