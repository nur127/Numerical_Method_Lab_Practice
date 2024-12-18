#include <bits/stdc++.h>
using namespace std;

#define nl endl
#define nur() ios::sync_with_stdio(false); cin.tie(0);

class NewtonForwardInterpolation {

private:

    vector<pair<double, double>> p;        
    vector<vector<double>> del;            
    int n;                                
    double h;                              

    int factorial(int x) {
        int fact = 1;
        for (int i = x; i > 0; i--) {
            fact *= i;
        }
        return fact;
    }
  
    double calcPvalue(double x0, double x) {
        return (x - x0) / h;
    }
  
    void calcDel() {
        del.assign(n, vector<double>(n, 0));      
        for (int i = 0; i < n; i++) {
            del[i][0] = p[i].second;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                del[i][j] = del[i + 1][j - 1] - del[i][j - 1];
            }
        }
    }

public:
 
    NewtonForwardInterpolation(vector<pair<double,double>>& points) {
        p = points;
        n = p.size();
        h = p[1].first - p[0].first;  
        calcDel();                    
    }

    double interpolate(double x) {
        double p_value = calcPvalue(p[0].first, x);
        double result = p[0].second;

        double p_term = 1.0;
        for (int i = 1; i < n; i++) {
            p_term *= (p_value - (i - 1));
            result += (p_term * del[0][i]) / factorial(i);
        }

        return result;
    }
};

int main() {
    nur();

    int n;
    double x;
    // cout << "Enter number of data points (n) and the value to interpolate (x): " <<nl;
    cin >> n >> x;

    vector<pair<double, double>> points(n);
    // cout << "Enter the data points (x, y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    
    NewtonForwardInterpolation interpolator(points);

    double interpolated_value = interpolator.interpolate(x);
    cout << "The interpolated value at x =  " << x << "  is:  " << interpolated_value << nl;

    return 0;
}
