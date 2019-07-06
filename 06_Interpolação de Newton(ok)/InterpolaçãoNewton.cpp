#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    int m = 5;

    double z = 2,result = 0.0;
    double x[m] = {0.1,0.6,0.8,1.2,1.8};
    double y[m] = {1.221,3.32,4.953,6.2,7.1};
    double aux_y[m] = {1.221,3.32,4.953,6.2,7.1};

    for (int k = 0;k<m;k++) {

        for (int i = m-1;i>k;i--) {

            aux_y[i] = (aux_y[i] - aux_y[i-1]) / (x[i] - x[i-k-1]);
        }
    }
    result = aux_y[m-1];
    for (int i = m-2;i>=0;i--) {
        result = result * (z - x[i]) + aux_y[i];
    }

    cout << "\n";
    cout << fixed << setprecision(10) << "\nResultado: " << result;

}
