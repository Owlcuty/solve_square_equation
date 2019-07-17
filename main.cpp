//! @file


#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int SS_INFINITY_ROOTS = -1;

int solve_square_equation(double a, double b, double c, double &x1, double &x2) {
    double d = 0;
    if (a == 0) {
        if (b == 0) {
            return (c == 0) ? SS_INFINITY_ROOTS : 0;
        } else {
            x1 = -c / b;
            return 1;
        }
    } else {
        d = sqrt(b * b - 4 * a * c);
        if (d > 0) {
            x1 = (-b + d) / (2 * a);
            x2 = (-b - d) / (2 * a);
            return 2;
        } else if (d == 0) {
            x1 = -b / (2 * a);
            return 1;
        } else {
            return 0;
        }
    }
}


/**
 //! @brief Entry point
 //!
 //! Solve square equation
 *
 //! @param a : a-coefficient
 //! @param b : b-coefficient
 //! @param c : c-coefficient
 //! @param x1 : first root
 //! @param x2 : second root
 *
 //! @return Nums of roots
 */

int main() {
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    cout << "# Kaidanov K.Yu.\n";
    cout << "# 2019\n\n";

    cout << "Enter a, b, c (coefficients):" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    int num_of_roots = solve_square_equation(a, b, c, x1, x2);

    cout << "Num of roots: ";
    if (num_of_roots != SS_INFINITY_ROOTS) cout << num_of_roots << "\n";
    else cout << "Infinity\n";

    if (num_of_roots > 0) printf((num_of_roots == 1) ? "x = %g\n" : "x1 = %g\n" "x2 = %g\n", x1, x2);

    return 0;
}