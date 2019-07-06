#include <stdio.h>
#include <math.h>

double fx(double ca, double vy, double vx, double m, double mi) {

    double valor = sqrt(pow(vx, 2) + pow(vy,2));
    return -(1/m) * ca * (valor* vx) - mi * vx;
}

double fy(double ca, double vy, double vx, double g ,double m, double mi) {

    double valor = sqrt(pow(vx, 2) + pow(vy,2));
    return -g -(1/m)*ca*(valor * vy) - mi * vy;
}

double gx(double vx) {

    return vx;
}

double gy(double vy) {

    return vy;
}

int main () {
	
    double k1[7],k2[7],k3[7],k4[7];
    double val_k1 = 0,val_k2 = 0, val_k3 = 0, val_k4 = 0;
    double m = 0.01;
    double ca = 0.0001;
    double mi = pow(18.68,-6);
    double g = 9.8;

    double t = 0;
    double h = 0.0001;
    double x = 0;
    double y = 0.3;
    double v0 = 100;
    double tetha =  3.14159 * 30 / 180;
    double vx = v0 * cos(tetha);
    double vy = v0 * sin(tetha);
    double A[7][7], B4[7], B5[7][1];

    A[0][0] = 0.0;
    A[1][0] = 1.0/5;
    A[2][0] = 3.0/40; A[2][1] = 9.0/40;
    A[3][0] = 44.0/45; A[3][1] = -56.0/15; A[3][2] = 32.0/9;
    A[4][0] = 19372.0/6561; A[4][1] = -25360.0/2187; A[4][2] = 64448.0/6561; A[4][3] = -212.0/729;
    A[5][0] = 9017.0/3168; A[5][1] = -355.0/33; A[5][2] = 46732.0/5247; A[5][3] = 49.0/176; A[5][4] = -5103.0/18656;
    A[6][0] = 35.0/384; A[6][1] = 0; A[6][2] = 500.0/1113; A[6][3] = 125.0/192; A[6][4] = -2187.0/6784; A[6][5] = 11.0/84;
    B4[0] = 5179.0/57600; B4[1] = 0.0; B4[2] = 7571.0/16695; B4[3] = 393.0/640; B4[4] = -92097.0/339200; B4[5] = 187.0/2100; B4[6] = 1.0/40;

    for (int i = 0;i<7;i++) {
        k1[i] = 0;
        k2[i] = 0;
        k2[i] = 0;
        k2[i] = 0;
    }
    k1[0] = h * fx(ca, vy, vx, m , mi);
    k2[0] = h * fy(ca, vy, vx, g, m , mi);
    k3[0] = h * gx(vx);
    k4[0] = h * gy(vy);

    while (y > 0.0001) {

        for (int j = 0; j < 6;j++) {
            val_k1 = 0,val_k2 = 0;
            for (int i = 0;i<=j;i++) {
                val_k1 = val_k1 + k1[i] * A[j+1][i];
                val_k2 = val_k2 + k2[i] * A[j+1][i];
            }
            k1[j+1] = fx(ca, vy + h*val_k2,vx + h*val_k1,m,mi);
            k2[j+1] = fy(ca, vy + h*val_k2,vx + h*val_k1,g,m,mi);
            k3[j+1] = gx(vx + h*val_k1);
            k4[j+1] = gy(vy + h*val_k2);
        }

        val_k1 = 0,val_k2 = 0, val_k3 = 0,val_k4 = 0;
        for (int i = 0;i<7;i++) {
            val_k1 = val_k1 + k1[i]*B4[i];
            val_k2 = val_k2 + k2[i]*B4[i];
            val_k3 = val_k3 + k3[i]*B4[i];
            val_k4 = val_k4 + k4[i]*B4[i];
        }


        vx = vx + h * val_k1;
        vy = vy + h * val_k2;
        x  =  x + h * val_k3;
        y  =  y + h * val_k4;
    }

    printf("\nAlcance: %f", x);




    return 0;
}
