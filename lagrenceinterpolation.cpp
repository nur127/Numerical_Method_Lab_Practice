#include<bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
private:
    vector<double> x,y; 

public:

    LagrangeInterpolation( vector<double>& x_points, vector<double>& y_points)
       {
        x = x_points;
        y = y_points;
       }

    double interpolate(double X) {

        double result = 0.0; 
        int n = x.size();

        for (int i = 0; i < n; i++) {

            double term = y[i]; 

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    term *= (X - x[j]) / (x[i] - x[j]);
                }
            }

            result += term; 
        }

        return result;
    }
};

int main() {

    int n ;
    // cout<<"Enter the value of n"<<endl;
    cin >> n ;
    vector<double> x(n),y(n);
    // cout<<"Enter the value of x and y"<<endl;
    for (int i = 0 ; i < n ; i++){
       cin >>x[i]>>y[i];
    }
    LagrangeInterpolation interpolator(x, y);

    // cout<<"Enter the value of Target Value"<<endl;
    double value;
    cin >> value ;

    cout << "Interpolated value at x = " << value << " is " << interpolator.interpolate(value) << endl;

    return 0;
}
