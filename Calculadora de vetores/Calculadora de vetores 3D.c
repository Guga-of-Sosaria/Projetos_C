#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void produto_vetorial(float a[], float b[], float resultado[]);
float modulo_vetor(float vetor[]);
float angulo(float a[], float b[]);

int main(void){
    float vetor1[3];
    float vetor2[3];
    float resultado[3];
    float *p1, *p2, *pr;
    bool rodando = true;
    int escolha;

    while (rodando)
    {
        printf("BEM VINDO! O QUE VOCÊ DESEJA FAZER HOJE?\n");
        printf("1) Multiplicação vetorial\n");
        printf("2) Calcular módulo\n");
        printf("3) Calcular ângulo entre vetores\n");
        printf("4) Fechar o programa\n");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            p1 = vetor1;
            p2 = vetor2;

            printf("Digite as coordenadas X, Y e Z do primeiro vetor:\n");
            for(int i = 0; i <= 2; i++){
                scanf("%f", (p1 + i));
            }

            printf("Agora, digite as coordenadas do segundo vetor:\n");
            for(int i = 0; i <= 2; i++){
                scanf("%f", (p2 + i));
            }

            produto_vetorial(vetor1, vetor2, resultado);

            pr = resultado;

            printf("(");
            for(int i = 0; i <= 2; i++){
                printf("%f ", *pr);
                pr++;
            }
            printf(")");
            printf("\n");
            printf("APERTE QUALQUER TECLA PARA CONTINUAR...\n");
            getch();
            system("cls");
           break;
        case 2:
            p1 = vetor1;
            
            printf("Digite as coordenadas X, Y e Z do vetor:\n");
            for(int i = 0; i <= 2; i++){
                scanf("%f", (p1 + i));
            }

            printf("%f\n", modulo_vetor(vetor1));
            printf("APERTE QUALQUER TECLA PARA CONTINUAR...\n");
            getch();
            system("cls");
            break;
        case 3:
            p1 = vetor1;
            p2 = vetor2;

            printf("Digite as coordenadas X, Y e Z do primeiro vetor:\n");
            for(int i = 0; i <= 2; i++){
                scanf("%f", (p1 + i));
            }
            
            printf("Agora, digite as coordenadas do segundo vetor:\n");
            for(int i = 0; i <= 2; i++){
                scanf("%f", (p2 + i));
            }

            printf("%f\n", angulo(vetor1, vetor2));
            printf("APERTE QUALQUER TECLA PARA CONTINUAR...\n");
            getch();
            system("cls");
            break;
        case 4:
            rodando = false;
        default:
            printf("OPERAÇÃO INVÁLIDA!\n");
            printf("APERTE QUALQUER TECLA PARA CONTINUAR...\n");
            getchar();
            system("cls");
            break;
        }
    }

    return 0;
}

void produto_vetorial(float a[], float b[], float resultado[])
{
    float arr1[] = {a[2], a[0], a[1], a[2], a[0]};
    float arr2[] = {b[2], b[0], b[1], b[2], b[0]};
    int i, k;
    float coord1, coord2;
    float *pr;

    pr = resultado;
    
    for(i = 1, k = 1; i <= 3; i++, k += 2){
        if(i + 2 <= 4){
            coord1 = arr1[i + 1] * arr2[i + 2];
        }
        else{
            coord1 = arr1[1] * arr2[2];
        }

        if (4 - k >= 0){
            coord2 = arr1[4 - k] * arr2[4 - k - 1];
        }
        else{
            coord2 = arr1[2] * arr2[1];
        }

        *pr = coord1 - coord2;
        pr++;  
    }
}

float modulo_vetor(float vetor[])
{
    int i;
    float modulo = 0;

    for(i = 0; i <= 2; i++){
        modulo += pow(vetor[i], 2);
    }

    modulo = sqrt(modulo);

    return modulo;
}

float angulo(float a[], float b[])
{
    int i;
    float angulo;
    int soma = 0;
    
    for(i = 0; i <= 2; i++){
        soma += (a[i] * b[i]);
    }

    angulo = acos(soma / (modulo_vetor(a) * modulo_vetor(b)));

    return angulo;
}