#include <iostream>
#include <string>

int main() {
    unsigned long answer = 0;
    // --- Your code here
    for (int i = 1; i < 1000; i++){
        if(i%5 == 0 || i%3 == 0){
            answer = i + answer;
        }
    }


    // ---
    std::cout << answer << std::endl;
    return 0;
}
