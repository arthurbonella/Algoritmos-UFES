
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

        k11 = h * fx(ca,vy, vx, m, mi);
        k12 = h * fy(ca,vy, vx, g, m, mi);
        k13 = h * gx(vx);
        k14 = h * gy(vy);

        t = t + 0.5 * h ;

        k21  = h * fx( ca, vy + 0.5 * k12, vx + 0.5 * k11, m, mi ) ;
        k22  = h * fy( ca, vy + 0.5 * k12, vx + 0.5 * k11, g, m, mi ) ;
        k23  = h * gx( vx + 0.5 * k11 ) ;
        k24  = h * gy( vy + 0.5 * k12 ) ;

        k31  = h * fx( ca, vy + 0.5 * k22, vx + 0.5 * k21, m, mi ) ;
        k32  = h * fy( ca, vy + 0.5 * k22, vx + 0.5 * k21, g, m, mi ) ;
        k33  = h * gx( vx + 0.5 * k21 ) ;
        k34  = h * gy( vy + 0.5 * k22 ) ;

        t = t + 0.5 * h ;

        k41  = h * fx( ca, vy + k32, vx + k31, m, mi ) ;
        k42  = h * fy( ca, vy + k32, vx + k31, g, m, mi ) ;
        k43  = h * gx( vx + k31 ) ;
        k44  = h * gy( vy + k32 ) ;

        vx = vx + (1.0/6.0) * ( 1.0 * k11 + 2.0 * k21 + 2.0 * k31 + 1.0 * k41 ) ;
        vy = vy + (1.0/6.0) * ( 1.0 * k12 + 2.0 * k22 + 2.0 * k32 + 1.0 * k42 ) ;
        x  =  x + (1.0/6.0) * ( 1.0 * k13 + 2.0 * k23 + 2.0 * k33 + 1.0 * k43 ) ;
        y  =  y + (1.0/6.0) * ( 1.0 * k14 + 2.0 * k24 + 2.0 * k34 + 1.0 * k44 ) ;

    }
    printf("\nAlcance: %f", x);
    return 0;
}
