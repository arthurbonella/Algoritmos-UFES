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

    double k11, k12, k13,k14,k21,k22,k23,k24,k31,k32,k33,k34, k41,k42,k43,k44;
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

    while (y > 0.0001) {
    	
        k11 = fx(ca,vy, vx, m, mi);
        k12 = fy(ca,vy, vx, g, m, mi);
        k13 = gx(vx + 0.5 * h * k11);
        k14 = gy(vy + 0.5 * h * k12);

        t = t + 0.33 * h;

        k21 = fx(ca,vy+0.5*h*k12, vx+0.5*h*k11, m, mi);
        k22 = fy(ca,vy+0.5*h*k12, vx+0.5*h*k11, g, m, mi);
        k23 = gx(vx + 0.5*h*k11);
        k24 = gy(vy + 0.5*h*k12);

        t = t + 0.33 * h;

        k31 = fx(ca,vy+0.5*h*k22, vx+0.5*h*k21, m, mi);
        k32 = fy(ca,vy+0.5*h*k22, vx+0.5*h*k21, g, m, mi);
        k33 = gx(vx+0.5*h*k21);
        k34 = gy(vy+0.5*h*k22);

        t = t + 0.34 * h;

        k41 = fx(ca, vy+0.5*h*k32, vx + 0.5*h*k31, m, mi);
        k42 = fy(ca, vy+0.5*h*k32, vx + 0.5*h*k31, g, m, mi);
        k43 = gx(vx + 0.5 * h * k31);
        k44 = gy(vy + 0.5 * h * k32);



        vx = vx + h * (0.17 * k11 + 0.33 * k21 + 0.33 * k31 + 0.17 * k41);
        vy = vy + h * (0.17 * k12 + 0.33 * k22 + 0.33 * k32 + 0.17 * k42);
        x = x + h * (0.17 * k13 + 0.33 * k23 + 0.33 * k33 + 0.17 * k43);
        y = y + h * (0.17 * k14 + 0.33 * k24 + 0.33 * k34 + 0.17 * k44);

    }

    printf("\nAlcance: %f", x);




    return 0;
}
