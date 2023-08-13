#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

// best to check against these constant expressions rather than repeating literals
const char* ADD = "add";
const char* SUB = "sub";
const char* MULT = "mult";
// types
const char* INT = "int";
const char* FLOAT = "float";
const char* STRING = "string";

// some functions will be defined inside this namespace and some will be outside
namespace rob {

    int add(int a, int b) {
        return a + b;
    }

    std::string add(std::string a, std::string b) {
        return a.substr(0, a.size() / 2) + b.substr(0, b.size() / 2);
    }

    std::string add(std::string a, int b) {
        return a + std::to_string(b);
    }

    std::string sub(std::string a, int b) {
        return a.substr(0, a.size() - b);
    }

    int sub(int a, int b) {
        return a - b * 5;
    }

    int mult(int a, int b) {
        return a * b;
    }

    std::string mult(std::string a, std::string b) {
        std::string c = "";
        for (char ac : a) {
            for (char bc : b) {
                c += ac;
                c += bc;
            }
        }
        return c;
    }

    // sub str str should produce a version of the first string trimmed at the end. The number of trimmed characters
    // should be equal to the first string's length minus the second string's length
    // mult str int should repeat the string int number of times with no separation between them
    // --- Your code here
    std::string sub(std::string a , std::string b){
        return a.substr(0,a.size()-b.size() );
    }

    std::string mult(std::string a, int b){
        std::string str;
        for (int i = 0; i < b; i++){
            str = a + str;
        }
        return str;
    }


    // ---
}


// helper functions for doing the conversion
bool numeric(const std::string& type) {
    return type == INT || type == FLOAT;
}

int ensureInt(const std::string& val, const std::string& type) {
    // take in a numeric value type and convert it to an int
    // take care to do rounding for float types
    // you may consider std::stoi and std::stof for this function
    // --- Your code here
    if(type == std::string{"float"}){
       float string_to_float = std::stof(val);
       int float_to_int = string_to_float;
       if(string_to_float - float_to_int >= 0.5){
       return float_to_int + 1;
       }
       else{
       return float_to_int;
       }
    }

    else{
       int string_to_int = std::stoi(val);
       return string_to_int;
    }
    // ---
}

int main() {
    std::ifstream input{"input.txt"};
    std::ofstream output{"output.txt"};

    while (input.peek() != std::ifstream::traits_type::eof()) {
        std::string op, typea, typeb, a, b;
        input >> op >> typea >> typeb >> a >> b;
        if (op == ADD) {
            if (numeric(typea) && numeric(typeb)) {
                int aa = ensureInt(a, typea);
                int bb = ensureInt(b, typeb);
                output << rob::add(aa, bb) << std::endl;
               // std::cout << rob::add(aa, bb) << std::endl;  
            } else if (typea == STRING && numeric(typeb)) {
                int bb = ensureInt(b, typeb);
                output << rob::add(a, bb) << std::endl;
               // std::cout << rob::add(a, bb) << std::endl; //
            } else if (typea == STRING && typeb == STRING) {
                output << rob::add(a, b) << std::endl;
               // std::cout << rob::add(a, b) << std::endl; //
            }
        } else if (op == SUB) {
            if (numeric(typea) && numeric(typeb)) {
                int aa = ensureInt(a, typea);
                int bb = ensureInt(b, typeb);
                output << rob::sub(aa, bb) << std::endl;
               // std::cout << rob::sub(aa, bb) << std::endl; //
            } else if (typea == STRING && numeric(typeb)) {
                int bb = ensureInt(b, typeb);
                output << rob::sub(a, bb) << std::endl;
               // std::cout << rob::sub(a, bb) << std::endl; //
            } else if (typea == STRING && typeb == STRING) {
                output << rob::sub(a, b) << std::endl;
               // std::cout << rob::sub(a, b) << std::endl; //
            }
        } else if (op == MULT) {
            if (numeric(typea) && numeric(typeb)) {
                int aa = ensureInt(a, typea);
                int bb = ensureInt(b, typeb);
                output << rob::mult(aa, bb) << std::endl;
               // std::cout << rob::mult(aa, bb) << std::endl; //
            } else if (typea == STRING && numeric(typeb)) {
                int bb = ensureInt(b, typeb);
                output << rob::mult(a, bb) << std::endl;
               // std::cout << rob::mult(a, bb) << std::endl; //
            } else if (typea == STRING && typeb == STRING) {
                output << rob::mult(a, b) << std::endl;
               // std::cout << rob::mult(a, b) << std::endl; //
            }
        }
    }
}