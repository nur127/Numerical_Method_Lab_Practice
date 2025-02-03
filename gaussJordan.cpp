#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nur() ios::sync_with_stdio(false); cin.tie(0);
const int SIZE = 10; // Max matrix size

class GaussJordan {
private:
    int n;             // Number of equations
    float A[SIZE][SIZE]; // Augmented matrix
    float X[SIZE];       // Solution array

public:
    // Constructor
    GaussJordan(int size) {
        n = size;
    }

    // Function to take input
    void inputMatrix() {
        cout << "Enter the coefficients of the augmented matrix (including constants):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cin >> A[i][j];
            }
        }
    }

    // Function to apply Gauss-Jordan Elimination
    void gaussJordanElimination() {
        for (int i = 0; i < n; i++) {
            // Make diagonal element 1 (Pivot Normalization)
            float pivot = A[i][i];
            for (int j = 0; j < n + 1; j++) {
                A[i][j] /= pivot;
            }

            // Make other elements in the column 0
            for (int k = 0; k < n; k++) {
                if (k != i) { // Avoid modifying pivot row
                    float factor = A[k][i];
                    for (int j = 0; j < n + 1; j++) {
                        A[k][j] -= factor * A[i][j];
                    }
                }
            }
        }
    }

    // Function to extract the solution
    void getSolution() {
        for (int i = 0; i < n; i++) {
            X[i] = A[i][n]; // Last column contains the solution
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

    GaussJordan solver(n);

    solver.inputMatrix();
    solver.gaussJordanElimination();
    solver.getSolution();
    solver.displaySolution();

    return 0;
}
