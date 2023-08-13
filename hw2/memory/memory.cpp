#include <iostream>
#include <fstream>
// below are some includes that are hints for what could make things easier
#include <string>
#include <vector>
#include <algorithm>

void processLine(std::string& line, int lineNumber, int* counter) {
    // line is passed in by reference, so you can modify it directly
    // do not return anything from this function
    // --- Your code here
    // ---
}

int* createCounter() {
    // this is a contrived function to get you more familiar with heap allocation
    // if you return a pointer to a local variable (on the stack), that value will be invalid after the return
    // and accessing it will be unexpected behavior (probably a segfault)
    // remember to initialize it to 0
    // --- Your code here



    // ---
}



int main() {
    // you will need to read the API of std::ofstream and std::ifstream
    std::ifstream input{"input.txt"};
    std::vector<std::string> lines;
    std::string line;

    // create a reference to the pointed value
    // references can be used more conveniently than pointers
    // note that the processLine function takes counter as a pointer, so you have to address it with &
    // contrived example to get you more familiar with going between references and pointers
    // usually there will not be so many unnecessary conversions
    int& counter = *createCounter();


    // --- Your code here



    // ---

    // output
    // --- Your code here



    // ---

   
    while (!input.eof()){
        getline(input, line);
        lines.push_back(line);
    }

    int e = 0, l = 0, t = 0, sum = 0;
    for (int i = lines.size() - 1; i >= 0; i--){
        std::string &str = lines[i];
        for (int j = 0; j < str.size(); j++){
            if (str[j] == 'e'){
                str[j] = '3';
                e++;
            }
            if (str[j] == 'l'){
                str[j] = '1';
                l++;
            }
            if (str[j] == 't'){
                str[j] = '7';
                t++;
            }
        }

        sum = (3*e + l + 7*t)*i + sum;
        e = 0; l = 0; t = 0;
    }
    std::ofstream output{"output.txt"};
    for (int i = lines.size()-1;i >= 0; i--){
        output << lines[i] << std::endl;
    }
        output << sum << std::endl;


    //delete &counter;  /
}