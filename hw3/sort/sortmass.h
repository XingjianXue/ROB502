#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ObjMassPair = std::pair<std::string, double>; //this defines the type ObjMassPair to be std::pair<std::string, double>

//define the operator << here
//define a function that compares ObjMassPair objects here (for use by std::sort)
//--- Your code here
void operator<< (ostream &os, vector<ObjMassPair> obj_mass){
    for (int i = 0; i < obj_mass.size();i++){
      os << obj_mass[i].first << " " << obj_mass[i].second << endl;
    }
}

bool compare(ObjMassPair&a, ObjMassPair&b){
  return a.second < b.second;
}


// ---
