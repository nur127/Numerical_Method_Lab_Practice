#include <bits/stdc++.h>
using namespace std;

#define nl endl
#define nur() ios::sync_with_stdio(false); cin.tie(0);

class LinearRegression {
private:
    double a, b;  // Regression coefficients
    vector<double> x, y;
    int m;  // Number of data points

public:
    // Constructor to initialize data
    LinearRegression(vector<double> xValues, vector<double> yValues) {
        x = xValues;
        y = yValues;
        m = x.size();
        calculateCoefficients();
    }

    // Function to calculate coefficients
    void calculateCoefficients() {
        double sumX = 0, sumY = 0, sumXY = 0, sqX = 0;

        for (int i = 0; i < m; i++) {
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sqX += x[i] * x[i];
        }

        double xbar = sumX / m;
        double ybar = sumY / m;

        b = ((m * sumXY) - (sumX * sumY)) / ((m * sqX) - (sumX * sumX));
        a = ybar - (b * xbar);
    }

    // Function to display results
    void displayResults() {
        cout << "Slope (b): " << b << nl;
        cout << "Intercept (a): " << a << nl;
    }
};

int main() {
    nur();
    int m;
    cout << "Enter the number of data points: ";
    cin >> m;

    vector<double> x(m), y(m);
    cout << "Enter the x and y values:\n";
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }

    // Create the LinearRegression object with input values
    LinearRegression model(x, y);

    // Display the computed coefficients
    model.displayResults();

    return 0;
}
