#include <chrono>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Eigen>
using namespace std;

int main(){
    Eigen::Vector3d p0{1,2,14};
    Eigen::Vector3d p1{3,6,3};
    Eigen::Vector3d p2{5,1,4};

    Eigen::Vector3d v1 = p1 - p0;
    Eigen::Vector3d v2 = p2 - p0;
    Eigen::Vector3d b{0,0,0};

    Eigen::MatrixXd M(2,3);
    M << v1[0], v1[1], v1[2],
         v2[0], v2[1], v2[2];


    cout << M.size() << endl;

            int sum = 0;
        for (int i = 0; i < 250; i++){
            
            // if (_d < inlier_threshold_) {
                sum = sum + 1;
            // }  
        }

}