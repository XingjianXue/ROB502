#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include<vector>
using namespace std;


int main() {
    // HINT: consider using std::to_string and std::reverse
    unsigned long largest_palandrome{0};
    // --- Your code here
    int palandrome = 0;
    vector<int>v;
    for (int i = 1000; i >= 100; i--){
        for (int j = 1000; j >= 100; j--){
            palandrome = i*j;
            string palandrome_str = to_string(palandrome);
            int sum = 0;
            for (int k = 0; k < palandrome_str.size(); k++){
                 if (palandrome_str[k] == palandrome_str[palandrome_str.size() - 1 - k]){
                     sum++;
                 }
            }
            if (sum == palandrome_str.size()){
                v.push_back(stoul(palandrome_str));
            }
        } 
    }
     sort(v.begin(),v.end());
     largest_palandrome = v[v.size() - 1];

    // ---
    std::cout << largest_palandrome << std::endl;
    return 0;
}