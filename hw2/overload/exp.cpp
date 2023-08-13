#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

int main(){
std::string a = "sssss", b = "sss";
std::cout << a.size() - b.size();
std::cout << a.substr(1,a.size() - b.size());
}