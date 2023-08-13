#include <cmath>
#include <iostream>
#include <fstream>

int main() {
    // check whether a value is within a given range, and if the “clip” flag is set, and it’s outside the range, clip it (3 args from stdin) 
    std::ifstream ifs("clip_input.txt");
    if (ifs.fail()) {
        std::cout << "Missing clip_input.txt file\n";
        return 0;
    }
    double min_value, max_value, value;
    bool clip;
    std::string line;
    while (!ifs.eof()) {
        ifs >> min_value;
        ifs >> max_value;
        ifs >> value;
        ifs >> clip;
        // --- Your code here
        int out_value;
        if (value > max_value && clip == 1){
            out_value = max_value;
        }
        else if (value < min_value && clip == 1){
            out_value = min_value;
        }
        else {
            out_value = value;
        }
        // ---
        std::cout << out_value << std::endl;
    }
    return 0;
}
