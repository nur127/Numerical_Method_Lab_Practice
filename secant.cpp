#include <bits/stdc++.h>

using namespace std;

class SecantMethod {
private:
    double tolerance;
    int maxIterations;

    double function(double x) {
        return x * x * x - x*x + 2; 
    }

public:
    SecantMethod(double tol = 1e-6, int maxIter = 1000) : tolerance(tol), maxIterations(maxIter) {}

    double findRoot(double x0, double x1) {
        for (int i = 0; i < maxIterations; ++i) {
            double f_x0 = function(x0);
            double f_x1 = function(x1);

            if (fabs(f_x1 - f_x0) < 1e-10) {
                cerr << "Difference between function values is too small. No convergence." << endl;
                return x1;
            }

            double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
            
            cout << "Iteration X" << i+1 << " = " << x1 << endl;

            if (fabs(x2 - x1) < tolerance) {
                cout << "Converged in " << i + 1 << " iterations." << endl;
                return x2;
            }

            x0 = x1;
            x1 = x2;
        }

        cout << "Max iterations reached. Solution may not have converged." << endl;
        return x1;
    }
};

int main() {
    SecantMethod solver(1e-6, 100);  
    double x0 = -2.0;                 
    double x1 = 3.0;            

    return 0 ;      

}