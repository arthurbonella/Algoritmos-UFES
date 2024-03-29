#include<stdio.h>
#include<math.h>

//Escrever a função, nos devolvendo o valor no ponto desejado
float f(float a){
	//função a = cos(a)-a;
	a = cos(a)-a;
	return a;
}

void regula (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*itr);
    printf("Iteração numero %3d X = %7.5f \n", *itr, *x);
}
void main ()
{
    int itr = 0, maxmitr;
    float x0,x1,x2,x3,allerr;
    printf("\nentre os valores de x0, x1, precisao e iterações maximas:\n");
    scanf("%f %f %f %d", &x0, &x1, &allerr, &maxmitr);
    regula (&x2, x0, x1, f(x0), f(x1), &itr);
    do
    {
        if (f(x0)*f(x2) < 0)
            x1=x2;
        else
            x0=x2;
        regula (&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3-x2) < allerr)
        {
            printf("Depois de %d iteração, raiz = %6.4f\n", itr, x3);
            return 0;
        }
        x2=x3;
    }
    while (itr<maxmitr);
    printf("Solução não converge ou sem iterações o suficiente:\n");
    return 1;
}
