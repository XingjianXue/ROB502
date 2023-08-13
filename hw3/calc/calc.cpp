#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


// --- Your code here
class calculation {
  private:
  vector<double>_num;
  public:
  calculation(vector<double>num){
       _num = num;
  }
  double plus(){
      double sum = 0;
      for (int i = 0; i < _num.size(); i++){
          sum += _num[i];
      }
      return sum;
    }
  double divide(){
      double div = _num[0]/_num[1];
      return div;
    }
  double multiply(){
      double mul = 1;
      for (int i = 0; i < _num.size(); i++){
          mul = _num[i]* mul;
      }
      return mul;
  }

};


// ---


int main()
{
  ifstream infile("input.txt");
  ofstream outfile("output.txt");


  //Read in each line from the input file,
  //perform the specified operation on the numbers,
  //and write the results to the ouputfile.
  //Remember to check if the specified operation is possible!
  // --- Your code here
  //}

  string str;
  vector<double>num;
  while (!infile.eof()){
  getline(infile, str);
    if(str.find("+")!=string::npos){
      str.erase(str.find("+"));
      while(!str.empty()){
         while(!str.find(" ") == string::npos){
              num.push_back(stoi(str));
              str.clear();
              break;
          }
         string s_temp = str.substr(0,str.find(" "));
         num.push_back(stod(s_temp));
         str.erase(0,str.find(" ") + 1);
      }
      if (num.size() == 1){
        outfile << num[0] << endl;
        num.clear();
      }
      else{
        calculation c(num);
        outfile << c.plus() << endl;
        num.clear();
      }
    } 


    if(str.find("/")!=string::npos){
      str.erase(str.find("/"));
      while(!str.empty()){
         while(!str.find(" ") == string::npos){
              num.push_back(stoi(str));
              str.clear();
              break;
          }
         string s_temp = str.substr(0,str.find(" "));
         num.push_back(stod(s_temp));
         str.erase(0,str.find(" ") + 1);
      }
      if (num.size()== 2 && num[1]!= 0){
      calculation c(num);
      outfile << c.divide() << endl;
      num.clear();
      }
      else{
      outfile << "ERROR" << endl;
      num.clear();
      }

    } 

    if(str.find("*")!=string::npos){
      str.erase(str.find("*"));
      while(!str.empty()){
                  while(!str.find(" ") == string::npos){
              num.push_back(stoi(str));
              str.clear();
              break;
          }
         string s_temp = str.substr(0,str.find(" "));
         num.push_back(stod(s_temp));
         str.erase(0,str.find(" ")+1);
      }
        calculation c(num);
        outfile << c.multiply() << endl;
        num.clear();
      } 


      
  }

  // ---
  return 0;
}
