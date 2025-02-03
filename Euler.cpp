#include <bits/stdc++.h>
using namespace std;

class Euler {
private:
    double func(double x, double y) {
        return x * x + y;
    }

public:
    void eulerMethod(double x0, double y0, double h, double x) {
        double y = y0; // Initialize y
        while (x0 < x) {
            y = y + h * func(x0, y);
            x0 = x0 + h;
        }
        cout << "The value of y is " << y << endl;
    }
};

int main() {
    Euler euler;
    double x0, y0, h, x;
    cout << "Enter the value of x0, y0, h, and x: ";
    cin >> x0 >> y0 >> h >> x;
    euler.eulerMethod(x0, y0, h, x);
    return 0;
}