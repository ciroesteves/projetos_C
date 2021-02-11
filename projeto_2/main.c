#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto2Lib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *li;
    int escolha, aux, y, z;
    FUNCIONARIO x;
    // alocando memoria para a lista
    li = cria_lista();

    inicio:
    printf("-----(PROGRAMA LISTA DE FUNCION�RIOS)-----\n\n");
    escolha = menu();
    system("cls");

    switch(escolha){
        case 1 :
            printf("-----( COLETA DE DADOS )-----\n\n");
            x = coleta_dados();
            y = adiciona_funcionario(li, x);
            if(y){
                printf("\nAdicionado com Sucesso!\n");
            }else{
                printf("\nFalha ao Adicionar!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 2 :
            printf("-----( EXCLUINDO FUNCION�RIO )-----\n\n");
            aux = ler_id();
            z = busca_funcionario(li, aux);
            if(z){
                printf("\nEncontrado com Sucesso!\n");
            }else{
                printf("\nFalha ao Encontrar!\n");
            }
            system("pause");
            system("cls");
            y = exclui_funcionario(li, aux);
            if(y){
                printf("\nRemovido com Sucesso!\n");
            }else{
                printf("\nFalha ao Remover!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 3 :
            printf("-----( EDITANDO FUNCION�RIO )-----\n\n");
            aux = ler_id();
            y = edita_funcionario(li, aux);
            if(y){
                printf("\nEditado com Sucesso!\n");
            }else{
                printf("\nFalha ao Editar!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 4 :
            printf("-----( BUSCANDO FUNCION�RIO )-----\n\n");
            aux = ler_id();
            y = busca_funcionario(li, aux);
            if(y){
                printf("\nImpresso com Sucesso!\n");
            }else{
                printf("\nFalha na Impress�o!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 5 :
            printf("-----( LISTA DE FUNCION�RIOS )-----\n\n");
            y = consulta_lista(li);
            if(y){
                printf("\nConsultado com Sucesso!\n");
            }else{
                printf("\nFalha na Consulta!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 6 :
            printf("-----( BUSCANDO FUNCION�RIO(S) POR SAL�RIO )-----\n\n");
            y = consulta_lista_sal(li);
            if(y){
                printf("\nConsultado com Sucesso!\n");
            }else{
                printf("\nFalha na Consulta!\n");
            }
            system("pause");
            system("cls");
            goto inicio;
            break;
        case 7 :
            printf("-----( APAGANDO DADOS E FINALIZANDO PROGRAMA )-----\n\n");
            apaga_lista(li);
            system("pause");
            return 0;
            break;
        default :
            printf("Opcao Invalida!\nDigite Qualquer tecla parada voltar ao menu\n");
            system("pause");
            system("cls");
            goto inicio;
    }
    return 0;
}
