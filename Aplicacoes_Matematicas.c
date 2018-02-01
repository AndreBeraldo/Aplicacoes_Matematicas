/**      Desenvolvido por: Andre Vitor Beraldo
*   Instituicao: Universidade Federal de Itajuba (UNIFEI)
*           Curso: Ciencias da Computacao
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamMax 100

struct ponto{
    float x;
    float y;
};

struct pilha{
    int arranjo[tamMax];
    int topo;
};

        //////////////////
        /*  PROTOTIPOS  */
        //////////////////

typedef struct ponto PONTO;
typedef struct pilha PILHA;
int main();
void bem_vindo();
void menu();
PONTO* pto_cria(float x, float y);
void pto_libera(PONTO* p);
float calc_distancia(PONTO *p1, PONTO *p2);
float calc_pitagoras(float c1, float c2, float hip);
PILHA* criaPilha();
void push(PILHA *p, int elemento);
int pop(PILHA *p);
int exibe_pilha(PILHA *p);


          ////////////
          /*  MAIN  */
          ////////////

int main(){
    menu();
}

        //////////////////
        /*   METODOS    */
        //////////////////

void bem_vindo(){
    printf("/--------------------------------------------------|\n");
    printf("|         UNIVERSIDADE FEDERAL DE ITAJUBA          |\n");
    printf("|           APLICACOES PARA MATEMATICA             |\n");
    printf("|--------------------------------------------------|\n");
    printf("|              ANDRE VITOR BERALDO                 |\n");
    printf("|--------------------------------------------------/\n");
}

void menu(){
    char valor_menu;
    while(1){
        system("cls");
        bem_vindo();
        printf("\nEscolha uma opcao: ");
        printf("\n1 - Distancia entre pontos");
        printf("\n2 - Teorema de Pitagoras");
        printf("\n3 - Conversor decimal-binario");
        printf("\n4 - Conversor binario-decimal");
        printf("\n\nx - Sair da aplicacao\n\n");

        printf("Escolha: ");
            scanf("%c", &valor_menu);
            switch(valor_menu){
                case '1':
                    system("cls");
                    printf(" ---------------------------\n");
                    printf("<   DISTANCIA ENTRE PONTOS  > \n");
                    printf(" ---------------------------\n\n");
                    float d, x1, x2, y1, y2;
                    PONTO *p, *q;

                    printf("Digite os valores: ");
                    printf("\nx1: ");
                        scanf("%f", &x1);
                    printf("y1: ");
                        scanf("%f", &y1);
                    printf("\nx2: ");
                        scanf("%f", &x2);
                    printf("y2: ");
                        scanf("%f", &y2);


                    p = pto_cria(x1,y1);
                    q = pto_cria(x2,y2);

                    d = calc_distancia(p,q);
                    printf("\nDistancia entre os PONTOs = %.2f \n", d);

                    pto_libera(p);
                    pto_libera(q);

                    printf("\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");
                break;
                case '2':
                    system("cls");
                    float c1,c2,hip;
                    printf(" ---------------------------\n");
                    printf("<   TEOREMA DE PITAGORAS    > \n");
                    printf(" ---------------------------\n\n");
                    printf("Coloque 0 na incognita!");
                    printf("\n\nValor do cateto 1: ");
                        scanf("%f", &c1);
                    printf("Valor do cateto 2: ");
                        scanf("%f", &c2);
                    printf("Valor da hipotenusa: ");
                        scanf("%f", &hip);
                    float res = calc_pitagoras(c1,c2,hip);

                    printf("\n\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");

                break;
                case '3':
                    system("cls");
                    PILHA *p_aux = criaPilha();
                    int valor_inteiro, resto;
                    printf(" ----------------------------------\n");
                    printf("<   CONVERSOR DECIMAL - BINÁRIO    > \n");
                    printf(" ----------------------------------\n\n");
                    printf("Entre com um numero inteiro: ");
                        scanf("%d", &valor_inteiro);
                    while(valor_inteiro>1){
                        resto = valor_inteiro%2;
                        push(p_aux, resto);
                        valor_inteiro /= 2;
                    }
                    if(valor_inteiro == 0 || valor_inteiro == 1){
                        push(p_aux, valor_inteiro);
                    }
                    printf("Valor binario: ");
                    exibe_pilha(p_aux);

                    printf("\n\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");
                break;
                case '4':
                    system("cls");
                    int num_bin, dec=0, i;
                    printf(" ----------------------------------\n");
                    printf("<   CONVERSOR BINÁRIO - DECIMAL    > \n");
                    printf(" ----------------------------------\n\n");
                    printf("Entre com um numero binario: ");
                        scanf("%d", &num_bin);
                        for(i = 0; num_bin > 0; i++)
                        {
                            dec = dec + pow(2, i) * (num_bin % 10);
                            num_bin /= 10;
                        }
                    printf("O decimal correspondente eh: %d\n\n", dec);
                    printf("\n\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");
                break;
                case 'x':
                    printf("\nObrigado pela execucao!\n");
                    getch();
                    exit(1);
                break;
            }

    }
}

PONTO* pto_cria(float x, float y){
    PONTO* p = (PONTO*) malloc(sizeof(PONTO));
    if(p!=NULL){
        p->x = x;
        p->y = y;
    }return p;
}

void pto_libera(PONTO* p){
    free(p);
}

float calc_distancia(PONTO *p1, PONTO *p2){
     float dx = p1->x - p2->x;
     float dy = p1->y - p2->y;
     return sqrt(dx*dx + dy*dy);
}

float calc_pitagoras(float c1, float c2, float hip){
    float aux=0;
    if(c1 == 0 && c2 > 0 && hip > 0){
        aux= ((hip*hip)-(c2*c2));
        aux= sqrt(aux);
        printf("\n\nResultado: %.3f", aux);
    }if(c2 == 0 && c1 > 0 && hip > 0){
        aux = ((hip*hip)-(c1*c1));
        aux= sqrt(aux);
        printf("\n\nResultado: %.3f", aux);
    }if(hip == 0 && c1 > 0 && c2 > 0){
        aux = ((c1*c1)+(c2*c2));
        aux= sqrt(aux);
        printf("\n\nResultado: %.3f", aux);
    }else{
        printf("\n Ocorreu um problema: ");
        printf("\n - Nao se forma triangulo.");
        printf("\n - Os valores devem ser positivos.");
        printf("\n - Eh necessario informar a incognita atraves de 0.");
        printf("\n - A hipotenusa é sempre maior que o valor dos catetos.");
    }
}

PILHA* criaPilha(){

    PILHA *p;
    p = (PILHA*) malloc (sizeof(PILHA));

    if(!p){
        printf("Erro na alocação");
        exit(1);
    }
    p->topo = -1;
    return p;
}

void push(PILHA *p, int elemento){

    p->topo++;
    if(p->topo > tamMax-1){
        printf("\nPilha cheia!\n");
    }else{
        p->arranjo[p->topo] = elemento;
    }
    return;
}

int pop(PILHA *p){
    int aux;
    if(p->topo < -1){
        printf("\nPilha vazia!");
    }else{
        aux = p->arranjo[p->topo];
        p->topo = p->topo -1;
        return aux;
    }
}

int exibe_pilha(PILHA *p){
    while(p->topo > -1){
        printf("%d", p->arranjo[p->topo]);
        p->topo = p->topo -1;
    }
}

