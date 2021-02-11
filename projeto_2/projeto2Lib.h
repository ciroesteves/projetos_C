typedef struct funcionario{
	int ID;
	char nome[30];
	char endereco[50];
	int idade;
	float salario;
	char cargo[15];
}FUNCIONARIO;

typedef struct elemento* Lista;

Lista *cria_lista();

int menu();

FUNCIONARIO coleta_dados();

int adiciona_funcionario(Lista *li,FUNCIONARIO func);

int ler_id();

int busca_funcionario(Lista *li, int ident);

int exclui_funcionario(Lista *li, int ident);

int consulta_lista(Lista *li);

int consulta_lista_sal(Lista *li);

int edita_funcionario(Lista *li, int ident);

void imprime_funcionario(FUNCIONARIO x);

void apaga_lista(Lista *li);
