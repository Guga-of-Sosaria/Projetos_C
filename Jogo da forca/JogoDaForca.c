#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

#define TAMANHO 65
#define TENTATIVAS 6

//protótipo da função que desenha a forca
void forca(int tentativas);
//protótipo de função que pega input de letra do usuário
char input(void);

int main(void)
{
    //Guarda a resposta certa
    char resposta[TAMANHO];
    //Guarda os espaços
    char espacos[TAMANHO];
    //Verificará se o jogador quer jogar outra partida
    char continuar;
    //Guarda palpite do usuário
    char palpite;
    //Armazena o número de tentativas
    int tentativas;
    //Mantém o loop principal do jogo
    bool rodando = true;
    //Verificará se uma letra já foi usada
    bool usado;
    //Verificará se o jogador acertou uma letra
    bool acertou;
    //ponteiros para as arrays "espacos" e "letras", respectivamente
    char *p1, *p2;

    //Loop principal do jogo
    while(rodando){
        //Inicializa a array que guardará as letras usadas
        char letras[37] = {NULL};
        //Inicializa a variável "tentativas"
        tentativas = TENTATIVAS;

        //Pega a resposta do jogo da forca
        printf("Bem vindo! Para comecar, peca para alguem digitar a palavra secreta:\n");
        fgets(resposta, TAMANHO, stdin);
        //Substitui o \n no final da string por um terminador nulo
        resposta[strlen(resposta)] = '\0';
        //Deixa todas as letras da resposta em maiúsculo
        for(int i = 0; i < strlen(resposta); i++){
            resposta[i] = toupper(resposta[i]);
        }

        //Inicializações do ponteiro da array "letras"
        p1 = letras;

        //Preenche os espaços que não estão em branco com asteriscos
        strcpy(espacos, resposta);
        p2 = espacos;
        for(int i = 0; i < strlen(espacos); i++){
            if(!isspace(*p2)){
                *p2 = "*";
            }
            p2++;
        }

        while(tentativas >= 0){
            //"Desenha" a tela do jogo
            system("cls");
            if(letras == NULL){
                printf("Letras usadas: \n");
            }
            else{
                printf("Letras usadas: %s\n", letras);
            }
            printf("Tentativas: %d\n", tentativas);
            forca(tentativas);
            putchar('\n');
            printf("%s\n", espacos);
            printf("Digite uma letra:\n ");

            //Pega input do usuário
            palpite = input();
            //Inicializa a flag "usado"
            usado = false;
            //Verifica se a letra já foi usada
            for(int i = 0; i < strlen(letras); i++){
                if(letras[i] == palpite){
                    usado = true;
                    break;
                }
            }

            //Se a letra já tiver sido usada avisa ao usuário
            if(usado){
                printf("Essa letra já foi usada! tente de novo!\n");
                system("pause");
                continue;
            }
            //Se a letra não tiver sido usada, adciona ela a lista de letras usadas
            else{  
                *p1 = palpite;
                p1++;
            }
            //inicializa a variável "acertou"
            acertou = false;
            //Verifica se a resposta tem a letra
            for(int i = 0; i < strlen(resposta); i++){
                if(palpite == resposta[i]){
                    acertou = true;
                    espacos[i] = resposta[i];
                }
            }

            if(acertou){
                printf("PARABÉNS! VOCE ACERTOU!\n");
                system("pause");
            }
            else{
                //Reduz as tentativas se o usuário errar
                tentativas--;
                printf("Que pena... Nao tem %c!\n", palpite);
                system("pause");
            }

            //Verifica se o usuário acertou todas as letras
            if(strcmp(resposta, espacos) == 0){
                printf("PARABÉNS! VOCE GANHOU! A PALAVRA ERA %s\n", resposta);
                break;
            }
        }

        //Mensagem caso o usuário tenha perdido
        if(tentativas < 0){
            printf("Voce perdeu! a palavra era %s\n", resposta);
        }
        

        //Pergunta ao usuário se ele quer jogar de novo
        while(true){
            printf("Voce deseja jogar de novo? (y/n)\n");
            continuar = input();
            if(continuar == 'Y') {
                break;
            }
            else if(continuar == 'N') {
                printf("Obrigado por jogar!\n");
                system("pause");
                rodando = false;
                break;
            }
            else {
                continue;
            }
        }
    }
    
    return 0;
}

//função para desenhar a forca
void forca(int tentativas)
{
    switch (tentativas)
    {
    case 5:
    printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||          \n");
    printf("||          \n");
    printf("||          \n");
    printf("||\n");
    printf("---------------\n");
        break;
    case 4:
    printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||           |\n");
    printf("||           |\n");
    printf("||          \n");
    printf("||\n");
    printf("---------------\n");
        break;
    case 3:
        printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||          /|\n");
    printf("||           |\n");
    printf("||          \n");
    printf("||\n");
    printf("---------------\n");
        break;
    case 2:
    printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||          /|\\\n");
    printf("||           |\n");
    printf("||          \n");
    printf("||\n");
    printf("---------------\n");
        break;
    case 1:
    printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||          /|\\\n");
    printf("||           |\n");
    printf("||           \\\n");
    printf("||\n");
    printf("---------------\n");
        break;
    case 0:
    printf("______________\n");
    printf("||           |\n");
    printf("||           0\n");
    printf("||          /|\\\n");
    printf("||           |\n");
    printf("||          /\\\n");
    printf("||\n");
    printf("---------------\n");
        break;
    default:
    printf("______________\n");
    printf("||           |\n");
    printf("||           \n");
    printf("||          \n");
    printf("||           \n");
    printf("||          \n");
    printf("||\n");
    printf("---------------\n");
        break;
    }
}

//Função para pegar input do usuário
char input(void)
{
    int c;

    c = getchar();

    while(getchar() != '\n');

    return toupper(c);
}