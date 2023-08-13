#include "operators.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {


  //you can test your operators here
  //feel free to change any of the code below
  //the expected cout output for the code is given to you in cout_output.txt 
  vector<int> v_int = {1, 2, 7, 8};
  vector<double> v_double =  {1.0, 2, 2.4, 7.2, 8};
  vector<double> v_double2 = {2, 2.4, 7.2, 8};
  vector<float> v_float = {-9.2, -3.4};

  cout << "v_double= " << v_double << endl;
  cout << "v_int= " << v_int << endl;
  cout << "v_float= " << v_float << endl;
  cout << "v_double+v_double= " << v_double + v_double << endl;

  ofstream outfile("cout_output.txt");
  outfile << "(v_double,v_double2)= " << (v_double, v_double2) << endl;
  outfile << "v_double= " << v_double << endl;
  outfile << "v_int= " << v_int << endl;
  outfile << "v_float= " << v_float << endl;
  outfile << "v_double+v_double= " << v_double + v_double <<endl;
  outfile << "v_double*v_double= " << v_double * v_double << endl;
  outfile << "v_double*5= " << v_double * 5 << endl;
  outfile << "v_double*v_double2= " << v_double + v_double2 << endl;
  outfile << "v_double/5= " << v_double/5 << endl;
  

  
  //  vector_operation p1;
  //  p1.a = v_double;
  //  vector_operation p2;
  //  p2.a =v_double2;
  //  vector_operation p3 = p1 + p2;

  //  for(int i = 0; i < p3.a.size(); i++){
  //     cout << p3.a[i] << " ";
  //  }

  // try {
  // cout << "v_double+v_double2= ";
  // cout << v_double + v_double2;//<<endl;
  // } catch (const std::invalid_argument &e) {
  //   cout << e.what() << endl;
  // }


  return 0;
}
