#include <iostream>
#include <vector>
using namespace std;


#define ERROR_MESSAGE std::invalid_argument("Error: vectors must be the same size")

template<typename T>
ostream& operator<<(ostream &os,vector<T>vec){
  for(int i = 0; i < vec.size(); i++){
    if (i == 0){
       os << "[" << vec[i] << ", ";
    }
    else if (i == vec.size()-1){
       os << vec[i] << "]";
    }
    else{
       os << vec[i] <<", ";
    }
  }
  return os;
}





template<typename T1, typename T2>
vector<double> operator+ (vector<T1>vec1, vector<T2>vec2){
vector<double>sum;
  if(vec1.size() != vec2.size()){
       throw ERROR_MESSAGE;
  }
  else if(vec1.size() == vec2.size()){
     for (int i = 0; i < vec1.size(); i++){
        sum.push_back(vec1[i] + vec2[i]);
     }   
  }
  return sum;
  }

// template<typename T1, typename T2>
// vector<double> operator* (vector<T1>vec1, vector<T2>vec2){
// vector<double>sum;
//   if(vec1.size() != vec2.size()){
//        //throw ERROR_MESSAGE;
//   }
//   else if(vec1.size() == vec2.size()){
//      for (int i = 0; i < vec1.size(); i++){
//         sum.push_back(vec1[i] * vec2[i]);
//      }     
//   }return sum;
//   }
template <typename T1, typename T2>
std::vector<double> operator-(const vector<T1> &a, const vector<T2> &b)
{
    vector<double> sub;
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            sub.push_back(a[i] - b[i]);
        }
    }
    else
        throw ERROR_MESSAGE;

    return sub;
}


template <typename T1, typename T2>
std::vector<double> operator*(const vector<T1> &a, const vector<T2> &b)
{
    vector<double> mult1;
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            mult1.push_back(a[i] * b[i]);
        }
        return mult1;
    }
    else
        throw ERROR_MESSAGE;
}


template<typename T1, typename T2>
vector<double> operator* (vector<T1>vec1, T2 scalar){
vector<double>sum;
     for (int i = 0; i < vec1.size(); i++){
        sum.push_back(vec1[i] * scalar);
     }
     return sum;
  }

template<typename T1, typename T2>
vector<double> operator* (T2 scalar, vector<T1>vec1){
vector<double>sum;
     for (int i = 0; i < vec1.size(); i++){
        sum.push_back(vec1[i] * scalar);
     }
     return sum;
  }

template<typename T1, typename T2>
vector<double> operator/ (T2 scalar, vector<T1>vec1){
vector<double>div;
     for (int i = 0; i < vec1.size(); i++){
        div.push_back(vec1[i]/scalar);
     }
     return div;
}

template<typename T1, typename T2>
vector<double> operator/ (vector<T1>vec1, T2 scalar){
vector<double>div;
     for (int i = 0; i < vec1.size(); i++){
        div.push_back(vec1[i]/scalar);
     }
     return div;
}

// template<typename T1, typename T2>
// vector<double> vec_concat(vector<T1>vec1, vector<T2>vec2){
// vector<double>concat;
// concat = vec1;
//      for (int i = 0; i < vec1.size(); i++){
//         concat.push_back(vec2[i]);
//      }
//      return concat;
// }

template <typename T1, typename T2>
std::vector<double> operator,(const vector<T1> &a, const vector<T2> &b)
{
    vector<double> conc;
    for (int i = 0; i < a.size(); i++)
    {
        conc.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        conc.push_back(b[i]);
    }
    return conc;
}

// template <typename T1, typename T2>
// std::vector<double> operator,(const vector<T1> &a, const vector<T2> &b)
// {
//     vector<double> conc;
//     for (int i = 0; i < a.size(); i++)
//     {
//         conc.push_back(a[i]);
//     }

//     for (int i = 0; i < b.size(); i++)
//     {
//         conc.push_back(b[i]);
//     }
//     return conc;
// }


        

// --- Your code here

// class vector_operation{
//   public:
//   vector<double>a;
//   vector_operation operator+(vector_operation &p){
//     vector_operation temp;
//     for(int i = 0; i < p.a.size(); i++){
//         temp.a.push_back(this->a.at(i) + p.a.at(i));
//     }
//     return temp;
//   }

// };

// ---

