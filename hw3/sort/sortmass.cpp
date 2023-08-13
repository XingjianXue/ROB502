#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "sortmass.h"

using namespace std;


int main() {
  ifstream objects("objects.txt");
  ofstream outfile("output.txt");
  string name;
  double mass;

  vector<ObjMassPair> obj_mass;
  //read the contents of the objects file in to the obj_mass vector
  // --- Your code here
  //ObjMassPair pair;
  while (objects.peek() != std::ifstream::traits_type::eof())
  { 
    string line;
    getline(objects,line);
    istringstream temp(line);
    temp >> name >> mass;
    obj_mass.push_back(ObjMassPair(name,mass));
  }

  



  // while(!objects.eof()){
  //   getline(,);
    
  //   objects >> mass;
  //   pair.first = name;
  //   pair.second = mass;
  //   obj_mass.push_back(pair);
  //   //pair.first.clear();
  // }
  //   obj_mass.pop_back();

 
  // for (int i = 0; i < obj_mass.size(); i++){
  //   for (int j = 0; j < obj_mass.size() - 1; j++){
  //         if(obj_mass[j].second > obj_mass[j + 1].second){
  //             swap(obj_mass[j],obj_mass[j+1]);
  //         }
  //      }
  //   }

  sort(obj_mass.begin(),obj_mass.end(),compare);

  // for (int i = 0; i < obj_mass.size(); i++){
  //   cout << obj_mass[i].first << obj_mass[i].second << endl;
  // }

 
  // ---

  //use std::sort to sort obj_mass. You will need to define
  //a function that compares ObjMassPair objects that is of
  //the form expected by std::sort

  // --- Your code here



  // ---

  //you will need to properly overload the << operator (in sortmass.h)
  //to print obj_mass to cout
  //look at the form expected in the given output.txt
  cout << obj_mass;
  outfile << obj_mass;

}
