#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double funcao(double x) {
    double y = exp(-1*cos(x)) / sqrt(2*x + 4);
    return y;
}

int main () {

    double a = 0.0, b = 2.0, h, x, result;

    int m = 200;

    h = (b - a) / m;
    x = a;

    result = (3 * h * funcao(x)) / 8;
    x = x + h;

    for (int i = 1;i<m;i++) {
        if (i % 3 == 0) {
            result += (3 * h * 2 * funcao(x)) / 8;
        }
        else {
            result += (3 * h * 3 * funcao(x)) / 8;
        }
        x = x + h;
    }
    result += (3 * h * funcao(b)) / 8;

    cout << setprecision(10) << "\nResultado: " << result;
}
