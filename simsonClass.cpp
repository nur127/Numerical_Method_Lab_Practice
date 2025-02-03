#include <bits/stdc++.h>
using namespace std;

#define nl endl
#define nur() ios::sync_with_stdio(false); cin.tie(0);

class SimpsonIntegration {
private:
    int n;        // Number of intervals
    double a, b;  // Lower & upper limits

    // Function to be integrated
    double func(double x) {
        return 1 / x;  // Example: f(x) = 1/x
    }

public:
    // Constructor to initialize values
    SimpsonIntegration(int intervals, double lower, double upper) {
        n = intervals;
        a = lower;
        b = upper;

        // Simpson's Rule requires an EVEN number of intervals
        if (n % 2 != 0) {
            cout << "Error: Simpson's Rule requires an even number of intervals.\n";
            exit(1);
        }
    }

    // Method to perform Simpson's 1/3 Rule integration
    double integrate() {
        double delX = (b - a) / double(n);
        double ans = (func(a) + func(b)); // First & last terms

        for (int i = 1; i < n; i++) {
            double x = a + i * delX;
            if (i % 2 == 1) { // Odd indices get multiplied by 4
                ans += 4 * func(x);
            } else { // Even indices get multiplied by 2
                ans += 2 * func(x);
            }
        }

        return (ans * delX) / 3.0;
    }
};

int main() {
    nur();
    int n;
    double a, b;

    // Taking input
    cin >> n >> a >> b;

    // Create an object for Simpson’s Rule
    SimpsonIntegration simpson(n, a, b);

    // Perform integration and print the result
    cout << fixed << setprecision(6) << simpson.integrate() << nl;

    return 0;
}
