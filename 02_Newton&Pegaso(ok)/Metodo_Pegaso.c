#include<stdio.h>
#include<math.h>

float funcao(float x){
    return cos(x) - x;
}


int main(){

    float a,b,x;
    float Fa,Fb,Fx;
    float tolerancia,Del_x,interMax;
    int inter;

    printf("Digite o valor do parametro A:");
    scanf("%f",&a);
    printf("Digite o valor do parametro B:");
    scanf("%f",&b);
    printf("Digite o valor da toleranciaancia:");
    scanf("%f",&tolerancia);
    printf("Digite o valor Maximo de Interacoes:");
    scanf("%f",&interMax);

    Fa = funcao(a);
    Fb = funcao(b);
    x = b;
    Fx = Fb;
    inter = 0;

    while((fabs(Del_x) > tolerancia && fabs(Fx) > tolerancia) || inter < interMax){

        Del_x = (-Fx/((Fb - Fa)) * (b - a));
        x = x + Del_x;
        Fx = funcao(x);

        if((Fx * Fb) < 0){
            a = b;
            Fa = Fb;
        }
        else{
            Fa = (Fa * Fb) / (Fb + Fx);
        }
        b = x;
        Fb = Fx;
        inter = inter + 1;
    }

    printf("\nResultado: %f",x);
    printf("\nInteracoes: %d",inter);
}
