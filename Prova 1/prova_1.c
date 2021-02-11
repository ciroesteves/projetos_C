//nome: Ciro Esteves Vieira – prontuário: GU3011321 – Turma: B.
//nome: Diego de Sá Lorandi – prontuário: GU3011216 – Turma: B.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct str_conta{
    int ID;
    char nome[25];
    int tipo;
    float saldo;
}Conta;

Conta *alocandoMemo(int n);
Conta coletaDados();
void imprime(Conta *cImpressao, int n);
void liberaMemo(Conta *cLiberar);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n, i;

    printf("Digite a Quantidade de Contas a Serem Gerenciadas:\n");
    scanf("%d", &n);
    Conta *dados = alocandoMemo(n);
    if(dados == NULL){
        printf("\nMemória Insuficiente!\n");
        exit(1);
    }

    for(i=0;i<n;i++){
        dados[i] = coletaDados();
    }

    imprime(dados, n);

    FILE *f1;
    f1 = fopen("arquivo1.txt", "wb");
    if(f1 == NULL){
        printf("\nErro na Abertura do Arquivo!\n");
        system("pause");
        exit(1);
    }
    fwrite(dados, sizeof(Conta), n, f1);
    fclose(f1);


    printf("\nantes do procedimento %d", dados[0].ID);
    liberaMemo(dados);
    printf("\ndepois do procedimento %d", dados[0].ID);
    free(dados);
    printf("\ndepois do free %d", dados[0].ID);
    printf("\nnao foi erro");
    system("pause");


return 0;
}

Conta *alocandoMemo(int n){
    Conta *aux = (Conta*)malloc(n*sizeof(Conta));
    if(aux == NULL){
        printf("\nMemória Insuficiente!\n");
        exit(1);
    }
return aux;
}

Conta coletaDados(){
    Conta x;
    fflush(stdin);
    printf("Digite o ID da Conta:\n");
    scanf("%d", &x.ID);
    fflush(stdin);
    printf("Digite o Nome do Usuário:\n");
    fgets(x.nome, 24, stdin);
    do{
    printf("Digite o Tipo de Conta:\nTecla 1 - Poupança\nTecla 2 - Corrente\n");
    scanf("%d", &x.tipo);
    }while(!(x.tipo == 1 || x.tipo == 2)); //Para obrigar o usuário a digitar 1 ou 2
    printf("Digite o Saldo da Conta:\n");
    scanf("%f", &x.saldo);
    system("cls");
return x;
}

void imprime(Conta *cImpressao, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("\nId:    %d", cImpressao[i].ID);
        printf("\nNome:  %s", cImpressao[i].nome);
        if(cImpressao[i].tipo == 1){
            printf("Tipo:  Poupança");
        }else if(cImpressao[i].tipo == 2){
            printf("Tipo:  Corrente");
        }
        printf("\nSaldo: %.2f", cImpressao[i].saldo);
        printf("\n____________________\n");
    }
    system("pause");
}

void liberaMemo(Conta *cLiberar){
    free(cLiberar);
}
