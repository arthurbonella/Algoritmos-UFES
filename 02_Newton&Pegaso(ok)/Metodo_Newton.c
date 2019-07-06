#include<stdio.h>
#include<math.h>

float funcao(float x){
    return (2 * pow(x,3) - cos(x+1) - 3);
}

float funcaoDerivada(float x){
    return (6*pow(x,2) + sin(x+1));
}

int main(){

    float x0,x1,precisaoA,precisaoB;
    float resultado;
    int k;

    printf("Valor de x0:");
    scanf("%f",&x0);
    printf("Precisao A:");
    scanf("%f",&precisaoA);
    printf("Precisao B:");
    scanf("%f",&precisaoB);


    if (fabs(funcao(x0)) < precisaoA){
        resultado = x0;
        printf("%f",fabs(funcao(x0)));
        printf("%f",precisaoA);
    }
    else{
        k = 1;
        while(fabs(funcao(x1)) > precisaoA || fabs(x1 - x0) > precisaoB){
            x1 = x0 - (funcao(x0)/funcaoDerivada(x0));
            x0 = x1;
            k = k + 1;
        }
    }
    printf("Resultado: %f",resultado);
    printf("\nContador: %d",k);
}
