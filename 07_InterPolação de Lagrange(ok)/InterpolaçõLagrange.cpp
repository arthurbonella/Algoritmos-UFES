#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    int m = 5;
    double z = 2,result = 0.0, c, d;
    double x[m] = {0.1,0.6,0.8,1.2,1.8};
    double y[m] = {1.221,3.32,4.953,6.2,7.1};

    for (int i = 0;i<m;i++) {
        c = 1.0;
        d = 1.0;
        for (int j = 0;j<m;j++) {
            if (i != j) {
                c = c * (z - x[j]);
                d = d * (x[i] - x[j]);
            }
        }
        result = result + ((y[i] * c) / d);
    }

    cout << fixed << setprecision(10) << "\nResultado: " << result;

}
