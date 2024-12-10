#include<bits/stdc++.h>

using namespace std;

class NewtonInterpolation {
private:
    vector<double> x; 
    vector<double> y; 
    vector<vector<double>> diffTable;

    void calculateDividedDifferences() {
        int n = x.size();
        diffTable.resize(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++) {
            diffTable[i][0] = y[i];
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                diffTable[i][j] = (diffTable[i + 1][j - 1] - diffTable[i][j - 1]) / (x[i + j] - x[i]);
            }
        }
    }

public:
    NewtonInterpolation(const vector<double>& xValues, const vector<double>& yValues)
        : x(xValues), y(yValues) {
        calculateDividedDifferences();
    }

    double interpolate(double value) {
        double result = diffTable[0][0];
        double product = 1.0;

        for (int i = 1; i < x.size(); i++) {
            product *= (value - x[i - 1]);
            result += diffTable[0][i] * product;
        }

        return result;
    }

    void displayDifferenceTable() {
        cout << "Divided Difference Table:\n";
        for (int i = 0; i < x.size(); i++) {
            for (int j = 0; j < x.size() - i; j++) {
                cout << setw(10) << diffTable[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the x and y values:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    NewtonInterpolation interpolation(x, y);

    interpolation.displayDifferenceTable();

    
    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    double result = interpolation.interpolate(value);
    cout << "The interpolated value at x = " << value << " is " << result << endl;

    return 0;
}
