#include <bits/stdc++.h>
using namespace std;

#define nl endl
#define nur() ios::sync_with_stdio(false); cin.tie(0);

class TrapezoidalIntegration {
private:
    int n;          
    double a, b;    

    double func(double x) {
        return 1 / x;  
    }

public:

    TrapezoidalIntegration(int intervals, double lower, double upper) {
        n = intervals;
        a = lower;
        b = upper;
    }

    double integrate() {
        double delX = (b - a) / (double)n;
        double ans = (func(a) + func(b)) / 2.0;

        for (int i = 1; i < n; i++) { 
            double x = a + i * delX;
            ans += func(x);
        }

        return ans * delX;
    }
};

int main() {
    nur();
    int n;
    double a, b;

    cin >> n >> a >> b;

    TrapezoidalIntegration integration(n, a, b);

    cout << fixed << setprecision(6) << integration.integrate() << nl;

    return 0;
}
