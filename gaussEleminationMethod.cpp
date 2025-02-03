#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nur() ios::sync_with_stdio(false); cin.tie(0);
const int SIZE = 10; // Max matrix size

class GaussianElimination {
private:
    int n;             // Number of equations
    float A[SIZE][SIZE]; // Augmented matrix
    float X[SIZE];       // Solution array

public:
    // Constructor to initialize the number of equations
    GaussianElimination(int size) {
        n = size;
    }

    // Function to take input for the augmented matrix
    void inputMatrix() {
        cout << "Enter the coefficients of the augmented matrix (including constants):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cin >> A[i][j];
            }
        }
    }

    // Function to perform forward elimination (converts to upper triangular matrix)
    void forwardElimination() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                float c = A[j][i] / A[i][i]; // Calculate multiplier
                for (int k = 0; k < n + 1; k++) {
                    A[j][k] -= c * A[i][k]; // Subtract row to eliminate variable
                }
            }
        }
    }

    // Function to perform back substitution to find unknown variables
    void backSubstitution() {
        for (int i = n - 1; i >= 0; i--) {
            X[i] = A[i][n]; // Start with the last column (constants)
            for (int j = i + 1; j < n; j++) {
                X[i] -= A[i][j] * X[j]; // Subtract known values
            }
            X[i] /= A[i][i]; // Divide by the coefficient of the variable
        }
    }

    // Function to display the solution
    void displaySolution() {
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << fixed << setprecision(2) << X[i] << nl;
        }
    }
};

int main() {
    nur();
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    GaussianElimination solver(n);
    
    solver.inputMatrix();
    solver.forwardElimination();
    solver.backSubstitution();
    solver.displaySolution();

    return 0;
}
