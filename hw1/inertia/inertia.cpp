#include <cmath>
#include <iostream>
#include <fstream>

int main()
{
    double mass, w, h, d;
    std::ifstream ifs("inertia_input.txt");
    ifs >> mass;
    ifs >> w;
    ifs >> h;
    ifs >> d;
    // you'll need to store the outputs in variables Ih, Iw, and Id.
    // --- Your code here
    double Ih, Iw, Id;
    Ih = (1.0/12) * mass * (pow(w,2) + pow(d,2));
    Iw = (1.0/12) * mass * (pow(d,2) + pow(h,2));
    Id = (1.0/12) * mass * (pow(w,2) + pow(h,2));
    // ---
    std::cout << "<ixx>" << Ih << "</ixx>\n";
    std::cout << "<iyy>" << Iw << "</iyy>\n";
    std::cout << "<izz>" << Id << "</izz>\n";
    return 0;
}
