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

    result = 0.5 * h * funcao(x);
    x = x + h;
    for (int i=1;i<m;i++) {
        result += h * funcao(x);
        x = x + h;
    }
    result += 0.5 * h * funcao(b);

    cout << setprecision(10) << "\nResultado: " << result;
}
