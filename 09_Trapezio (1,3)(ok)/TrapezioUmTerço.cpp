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

    result = (h*funcao(x)) / 3;
    x = x + h;
    for (int i = 1;i<m;i++) {
        if (i % 2 != 0) {
            result = result + (h*4*funcao(x)) / 3;
        }
        else {
            result += (h*2*funcao(x)) / 3;
        }
        x = x + h;
    }
    result += (h*funcao(b)) / 3;

    cout << setprecision(10) << "\nResultado: " << result;
}
