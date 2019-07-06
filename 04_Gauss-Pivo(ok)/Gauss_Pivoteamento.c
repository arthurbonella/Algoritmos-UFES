#include <stdio.h>
#include <stdlib.h>

float* criaVetor(int Tamanho){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

  int i; //Variáveis Auxiliares

  float *v = (float*)malloc(Tamanho * sizeof(float)); //Aloca um Vetor de Ponteiros

  for (i = 0; i < Tamanho; i++){ //Percorre as linhas do Vetor de Ponteiros
       printf("Digite o valor de b[%d]:",i+1);
       scanf("%f",&v[i]);
  }
return v; //Retorna o Ponteiro para a Matriz Alocada
}

float ** criaMatriz(int Tamanho){

  int i,j; //Variáveis Auxiliares

  float **m = (float**)malloc(Tamanho * sizeof(float*)); //Aloca um Vetor de Ponteiros

 //Aloca memoria para a matriz
  for (i = 0; i < Tamanho; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (float*) malloc(Tamanho * sizeof(float)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
  }
  //Preenche os valores da matriz
  for (i = 0; i < Tamanho; i++){ //Percorre as linhas do Vetor de Ponteiros

       for (j = 0; j < Tamanho; j++){ //Percorre o Vetor de Inteiros atual.
            printf("Digite o valor de a[%d][%d]:",i+1,j+1);
            scanf("%f",&m[i][j]);
       }
  }

return m;

}

void printaMatriz (float** m,int Tamanho){

	int i,j;
	for (i = 0; i < Tamanho; i++){ //Percorre as linhas do Vetor de Ponteiros

       printf("\n");
       for (j = 0; j < Tamanho; j++){ //Percorre o Vetor de Inteiros atual.
            printf("%f | ",m[i][j]);
       }
  	}
}
void printaVetor (float* v, int Tamanho){

	int i;

	printf("\n");

	for (i = 0; i < Tamanho; i++){ //Percorre as linhas do Vetor de Ponteiros
       printf("%f | ",v[i]);
  	}
}

int main (){

    float **a;
	float *b;
	float *x;
	int n,i,j,k;
	float s,m;

	printf("Digite o tamanho 'n' da matriz[n][n]: ");
	scanf("%d",&n);

	x = (float*)malloc(n * sizeof(float));

	a = criaMatriz(n);
	b = criaVetor(n);

	n--;//Só porque os indices vao ate tam-1



	//printf("foi 0");
	printf("Matriz A:");
	printaMatriz(a,n+1);
	printf("\nVetor B:");
	printaVetor(b,n+1);

	//Pivoteamento
	int *aux;
	aux = (int*)malloc(sizeof(int)*n);

	for(i=0;i>n;i++){//Percorre as linhas e dita o termo da diagonal

		for(j=0;j>n;j++){//Percorre a coluna da linha,checando valores de referencia

			if (a[j][i]>a[i][i]){

				for(k = 0;k>n;k++){//percorre o vetor auxiliar o preenchendo com os valores a serem substituidos

					aux[k] = a[i][k];//Linha fixa, coluna variavel.(linha da diagongal)
					a[i][k] = a[j][k];//Linha fixa, coluna variavel.(linha fora da diagonal)
					a[j][k] = aux[k];//Retorna a linha originaria da diagonal para a posicao da fora da diagonal

				}

			}
		}
	}


	printf("\nMatriz A-pivoteada:");
	printaMatriz(a,n+1);

	x[n] = b[n]/a[n][n];

	//Eliminação
	k = 0;
	//for(k=0;k<=n-1;k++){
	while(k<=n-1){

		i = k+1;

		while(i<=n){

			m = a[i][k]/a[k][k];
			a[i][k] = 0;

			j = k+1;

			while(j<=n){

				a[i][j]= a[i][j]-(m*a[k][j]);

				j++;
			}

			b[i]=b[i]-(m*b[k]);

			i++;
		}

		k++;
	}
	//Sistema triangulado
	printf("\nMatriz A-triang:");
	printaMatriz(a,n+1);
	//Resolução do sistema
	i = n;

	while(i != -1){
		//printf("foi 1");
		s = 0;

		j = i;

		while (j<=n){

			s = s + (a[i][j]*x[j]);
			//printf("foi 2");
			j++;

		}

		x[i] = (b[i] - s)/ a[i][i];
		i = i-1;
	}

	printf("\nVetor X:");
	printaVetor(x,n+1);

}
/*
A
Digite o tamanho 'n' da matriz[n][n]: 3
Digite o valor de a[1][1]:3
Digite o valor de a[1][2]:2
Digite o valor de a[1][3]:4
Digite o valor de a[2][1]:0
Digite o valor de a[2][2]:0.333333
Digite o valor de a[2][3]:0.666666
Digite o valor de a[3][1]:0
Digite o valor de a[3][2]:0
Digite o valor de a[3][3]:-8
Digite o valor de b[1]:1
Digite o valor de b[2]:1.666667
Digite o valor de b[3]:0
Matriz A:
3.000000 | 2.000000 | 4.000000 |
0.000000 | 0.333333 | 0.666666 |
0.000000 | 0.000000 | -8.000000 |
Vetor B:
1.000000 | 1.666667 | 0.000000 |
Vetor X:
-3.000004 | 5.000006 | -0.000000 |
Process returned 0 (0x0)   execution time : 21.167 s
Press any key to continue.

B
Digite o tamanho 'n' da matriz[n][n]: 3
Digite o valor de a[1][1]:3
Digite o valor de a[1][2]:2
Digite o valor de a[1][3]:4
Digite o valor de a[2][1]:1
Digite o valor de a[2][2]:1
Digite o valor de a[2][3]:2
Digite o valor de a[3][1]:4
Digite o valor de a[3][2]:3
Digite o valor de a[3][3]:2
Digite o valor de b[1]:1
Digite o valor de b[2]:2
Digite o valor de b[3]:3
Matriz A:
3.000000 | 2.000000 | 4.000000 |
1.000000 | 1.000000 | 2.000000 |
4.000000 | 3.000000 | 2.000000 |
Vetor B:
1.000000 | 2.000000 | 3.000000 |
Matriz A-triang:
3.000000 | 2.000000 | 4.000000 |
0.000000 | 0.333333 | 0.666667 |
0.000000 | 0.000000 | -4.000000 |
Vetor X:
-3.000000 | 8.000000 | -1.500000 |
Process returned 0 (0x0)   execution time : 23.070 s
Press any key to continue.


*/
