#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto2Lib.h"

// estrutura dados+ponteiro
struct elemento{
	FUNCIONARIO dados;
	struct elemento *prox;
};
// renomeando a estrutura elemento
typedef struct elemento ELEM;
// funcao para criar a lista
Lista *cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}
// menu de opções
int menu(){
    int escolha;
    printf("Digite o numero correspondente a funcao desejada:\n1- Adicionar Funcionário \n2- Excluir Funcionário \n3- Editar Funcionário \n4- Buscar Funcionário \n5- Exibir Funcionário por Ordem de ID \n6- Exibir Funcionário(s) por faixa salarial \n7- Sair da Aplicação\n");
    scanf("%d", &escolha);
return escolha;
}
// coleta de dados
FUNCIONARIO coleta_dados(){
    FUNCIONARIO c;
    printf("Digite o ID do Funcionário:\n");
    scanf("%d", &c.ID);
    printf("Digite o Nome:\n");
    fflush(stdin);
    fgets(c.nome,30,stdin);
    printf("Digite o Endereco:\n");
    fflush(stdin);
    fgets(c.endereco,50,stdin);
    printf("Digite a Idade:\n");
    scanf("%d", &c.idade);
    printf("Digite o Salário:\n");
    scanf("%f", &c.salario);
    printf("Digite o Cargo:\n");
    fflush(stdin);
    fgets(c.cargo,15,stdin);
    system ("cls");
return c;
}
// adiciona funcionario de forma ordenada pelo id
int adiciona_funcionario(Lista *li,FUNCIONARIO func){
	if(li == NULL){
		return 0;
	}
	ELEM *no = (ELEM*) malloc (sizeof(ELEM));
		if(no == NULL){
			return 0;
		}
	no->dados = func;
	if((*li)==NULL){
        no->prox = (*li);
		*li = no;
		return 1;
	}
	else{
		ELEM *ant, *atual = *li;
		while(atual != NULL && atual->dados.ID < func.ID){
			ant = atual;
			atual = atual->prox;
		}
		if(atual == *li){
            no->prox = (*li);
            *li = no;
		}else{
            no->prox = ant->prox;
            ant->prox = no;
		}
	return 1;
	}
}
// funcao apenas para ler o id do funcionario
int ler_id(){
    int aux;
    printf("Digite o ID do funcionário:\n");
    scanf("%d", &aux);
return aux;
}
// buscar funcionario por id
int busca_funcionario(Lista *li, int ident){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.ID != ident){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
    imprime_funcionario(no->dados);
    return 1;
    }
}
// exclui funcionario especifico
int exclui_funcionario(Lista *li, int ident){
    int escolha;
    printf("Deseja Confirmar a Exclusão?\n1- Sim \nOutro- Não");
    scanf("%d", &escolha);
    if(escolha == 1){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.ID != ident){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
    }else{
        return 0;
    }
}
// consulta toda a lista de funcionarios
int consulta_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){
        imprime_funcionario(no->dados);
        no = no->prox;
    }
    if(no == NULL){
        return 1;
    }
    return 0;
}
// consulta por salario
int consulta_lista_sal(Lista *li){
    float min, max;
    printf("Digite o Limite Inferior do Salário Buscado:\n");
    scanf("%f", &min);
    printf("Digite o Limite Superior do Salário Buscado:\n");
    scanf("%f", &max);
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){
        if(no->dados.salario >= min && no->dados.salario <= max){
            imprime_funcionario(no->dados);
        }
        no = no->prox;
    }
    if(no == NULL){
        return 1;
    }
    return 0;
}
// edita o funcionario
int edita_funcionario(Lista *li, int ident){
    FUNCIONARIO x;
    float reaj;
    int escolha;
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.ID != ident){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
    imprime_funcionario(no->dados);
    }
    printf("\nVocê deseja:\n1- Editar Informações\n2- Fazer Reajuste Salarial\nOutros- Voltar ao menu\n");
    scanf("%d", &escolha);
    switch(escolha){
        case 1 :
            printf("-----( EDIÇÃO DE DADOS )-----\n\n");
            printf("***Não Altere o ID do Funcionário***\n");
            x = coleta_dados();
            no->dados = x;
            return 1;
            break;
        case 2 :
            printf("-----( REAJUSTE SALARIAL )-----\n\n");
            printf("Qual o Valor do Reajuste em porcentagem:\n");
            scanf("%f", &reaj);
            no->dados.salario = no->dados.salario + ((no->dados.salario*reaj)/100);
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
// funcao para imprimir os resultados
void imprime_funcionario(FUNCIONARIO x){
    printf("\nID: %d", x.ID);
    printf("\nNome: %s", x.nome);
    printf("Endereço: %s", x.endereco);
    printf("Idade: %d", x.idade);
    printf("\nSalário: %.2f", x.salario);
    printf("\nCargo: %s", x.cargo);
}
// funcao para apagar lista
void apaga_lista(Lista *li){
	if(li != NULL){
		ELEM *no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}
