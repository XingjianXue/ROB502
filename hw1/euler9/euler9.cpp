#include <iostream>

int euler9() {
    // --- Your code here
    int a; int b; int c;
    for (int i = 1; i <= 1000; i++){
        a = i;
        for (int j = 1; j <=1000; j++){
            b = j;
           for (int k = 1; k <= 1000; k++){
               c = k;
               if (a + b + c == 1000 && a*a + b*b == c*c && a < b && b < c){
                return a*b*c;
               }
           }
        }
    }

   
    // ---
}

int main() {
    // This code is a lot cleaner if you write it as a function, because you can use `return` once you find the answer
    int const product = euler9();
    std::cout << product << std::endl;
    return 0;
}
