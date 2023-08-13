#include <random>
#include <iomanip>
#include <iostream>
#include <eigen3/Eigen/Eigen>
#include <vector>

struct Plane
{
    double a;
    double b;
    double c;
    double d;
};

struct FitResult
{
    Plane plane;
    int n_inliers = -1;
};

void pretty_print(std::string const &input_filename, Plane const &plane)
{
    std::cout << std::setprecision(3) << "--infile " << input_filename << " -a " << plane.a << " -b " << plane.b << " -c " << plane.c << " -d " << plane.d << '\n';
}

std::ostream &operator<<(std::ostream &os, Plane const &plane)
{
    os << std::setprecision(3) << plane.a << " " << plane.b << " " << plane.c << " " << plane.d;
    return os;
}

Plane compute_plane_from_points(Eigen::Vector3d const &p0,Eigen::Vector3d const &p1,Eigen::Vector3d const &p2)
{
    // 1. given p0, p1, and p2 form two vectors v1 and v2 which lie on the plane
    // 2. use v1 and v2 to find the normal vector of the plane `n`
    // 3. set a,b,c from the normal vector `n`
    // 4. set `d = -n.dot(p0)`
    // --- Your code here
    Plane r1;
    //Eigen::Vector3d v1 = p1 - p0;
    //Eigen::Vector3d v2 = p2 - p0;
    Eigen::Vector3d b{p0[2],p1[2],p2[2]};
    Eigen::Vector3d x;
    Eigen::Matrix3d M;
    M << p0[0], p0[1], 1,
         p1[0], p1[1], 1,
         p2[0], p2[1], 1;
    x = M.inverse()*b;
    r1.a = x[0];
    r1.b = x[1];
    r1.c = -1;
    r1.d = x[2];   
    return r1;
    // ---
}

class BaseFitter
{
public:
    BaseFitter(int num_points) : mt(rd()), dist(0, num_points - 1)
    {
        mt.seed(0);
    }

    /**
     * Given all of the data `points`, select a random subset and fit a plane to that subset.
     * the parameter points is all of the points
     * the return value is the FitResult which contains the parameters of the plane (a,b,c,d) and the number of inliers
     */
    virtual FitResult fit(Eigen::MatrixXd const &points) = 0;

    int get_random_point_idx()
    {
        return dist(mt);
    };

    double const inlier_threshold_{0.02};

private:
    // These are for generating random indices, you don't need to know how they work.
    // Just use `get_random_point_idx()` and `points.row(rand_idx)`
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};

class AnalyticFitter : public BaseFitter
{
public:
    AnalyticFitter(int num_points) : BaseFitter(num_points) {}

    // by writing `override`, the compiler will check that this function actually overrides something 
    // in the base class. Always use this to prevent mistakes in the function signature!
    FitResult fit(Eigen::MatrixXd const &points) override
    {
        // 1. select 3 points from `points` randomly 
        // 2. compute the equation of the plane (HINT: use compute_plane_from_points)
        // 3. compute the `n_inliers` given that plane equation
        // (HINT: multiply the points matrix by the normal vector)
        // --- Your code here
        Eigen::Vector3d p0,p1,p2;
        int idx0 = get_random_point_idx();
        int idx1 = get_random_point_idx();
        int idx2 = get_random_point_idx();
        p0 = points.row(idx0);
        p1 = points.row(idx1);
        p2 = points.row(idx2);
        Plane analytic_plane = compute_plane_from_points(p0,p1,p2);
        Eigen::Vector3d n{analytic_plane.a,analytic_plane.b,analytic_plane.c};
        int sum = 0;
        for (int i = 0; i < points.size()/3; i++){   
            double _d = abs(points.row(i).dot(n)+ analytic_plane.d)/sqrt(n.dot(n));
            if (_d < inlier_threshold_) {
                sum++;
            }  
        }
        int n_inliers = sum;
        // ---
        return {analytic_plane, n_inliers};
    }
};

class LeastSquaresFitter : public BaseFitter
{
public:
    LeastSquaresFitter(int num_points, int n_sample_points) : BaseFitter(num_points), n_sample_points_(n_sample_points) {}

    // You should override the `fit` method here
    // --- Your code here
    FitResult fit(Eigen::MatrixXd const &points) override
    {
        int idx0 = get_random_point_idx();
        int idx1 = get_random_point_idx();
        int idx3 = get_random_point_idx();
        int idx2 = get_random_point_idx();
        int idx4 = get_random_point_idx();
        int idx5 = get_random_point_idx();
        int idx6 = get_random_point_idx();
        int idx7 = get_random_point_idx();
        int idx8 = get_random_point_idx();
        int idx9 = get_random_point_idx();
        Eigen::Vector3d p0,p1,p2,p3,p4,p5,p6,p7,p8,p9;
        p0 = points.row(idx0);
        p1 = points.row(idx1);
        p2 = points.row(idx2);
        p3 = points.row(idx3);
        p4 = points.row(idx4);
        p5 = points.row(idx5);
        p6 = points.row(idx6);
        p7 = points.row(idx7);
        p8 = points.row(idx8);
        p9 = points.row(idx9);

        Eigen::Matrix<double,10,3> M;
        M << p0[0], p0[1], 1,
             p1[0], p1[1], 1,
             p2[0], p2[1], 1,
             p3[0], p3[1], 1,
             p4[0], p4[1], 1,
             p5[0], p5[1], 1,
             p6[0], p6[1], 1,
             p7[0], p7[1], 1,
             p8[0], p8[1], 1,
             p9[0], p9[1], 1;
        
        Eigen::VectorXd V(10);
        V << p0[2],
        p1[2],
        p2[2],
        p3[2],
        p4[2],
        p5[2],
        p6[2],
        p7[2],
        p8[2],
        p9[2];  
        
        Eigen::Vector3d x = M.colPivHouseholderQr().solve(V);
        Plane analytic_plane{x[0],x[1],-1,x[2]};
        Eigen::Vector3d n{analytic_plane.a,analytic_plane.b,analytic_plane.c};
        int sum = 0;
        for (int i = 0; i < points.size()/3; i++){
            double _d = abs(points.row(i).dot(n)+ analytic_plane.d)/sqrt(n.dot(n));
            if (_d < inlier_threshold_) {
                sum++;
            }  
        }
        int n_inliers = sum;
        // ---
        return {analytic_plane, n_inliers};
    }


    // ---

    int const n_sample_points_;
};

Plane ransac(BaseFitter &fitter, Eigen::MatrixXd const &points)
{
    // --- Your code here
    FitResult best_result;
    best_result.n_inliers = fitter.fit(points).n_inliers;
    for (int i = 0; i < 1000; i++){
        if(fitter.fit(points).n_inliers > best_result.n_inliers){
                best_result.n_inliers = fitter.fit(points).n_inliers;
                best_result.plane =  fitter.fit(points).plane;  
        }
    }

    
    // ---

    // HINT: the number of inliers should be between 20 and 80 if you did everything correctly
    std::cout << best_result.n_inliers << std::endl;
    return best_result.plane;
}


