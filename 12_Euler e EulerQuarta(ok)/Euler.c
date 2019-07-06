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
        t = t + h ;
        vx = vx + h * fx( ca, vy, vx, m ,mi) ;
        vy = vy + h * fy( ca, vy, vx, g, m ,mi) ;
        x  =  x + h * gx( vx ) ;
        y  =  y + h * gy( vy ) ;
    }

    printf("\nAlcance: %f", x);




    return 0;
}

