#include <fstream>
#include <iomanip>
#include <iostream>
#include <eigen3/Eigen/Eigen>
using namespace std;
Eigen::Vector3d transform_mat(double q, double l)
{
    // --- Your code here
    Eigen::Matrix3d m;
    m << cos(q), -sin(q), 0,
         sin(q), cos(q), 0,
         0, 0, 1;
    Eigen::Vector3d i(l,0,1);
    i << l,
         0,
         1;
    Eigen::Vector3d v = m*i;
    return v;
    // ---
}

int main(int argc, char* argv[])
{
    // by defult, use the file joint_angles.txt, but if you supply a command line argument, use that instead
    std::string input_filename{"joint_angles.txt"};
    if (argc >= 2) {
        input_filename = argv[1];
    }
    std::ifstream ifs(input_filename);

    if (!ifs.good()) {
        std::cerr << "Failed to open file " << input_filename << std::endl;
        return 0;
    }

    double l1{1.0};
    double l2{0.5};
    double l3{0.25};

    while (ifs.peek() != -1)
    {
        double q1, q2, q3;
        ifs >> q1 >> q2 >> q3;
        // --- Your code here
        double dx1,dx2,dx3,dy1,dy2,dy3;
        dx1 = transform_mat(q1, l1)(0);
        dy1 = transform_mat(q1, l1)(1);
        dx2 = transform_mat(q1+q2, l2)(0);
        dy2 = transform_mat(q1+q2, l2)(1);
        dx3 = transform_mat(q1+q2+q3, l3)(0);
        dy3 = transform_mat(q1+q2+q3, l3)(1);
        cout << setprecision(3) << dx1+dx2+dx3 << endl;
        cout << setprecision(3) << dy1+dy2+dy3 << endl;
        // ---
    }
}