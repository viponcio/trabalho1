//criar um sistema para farmacia, onde devemos cadastrar, remove, busca, lista medicamentos e clientes.
//apagar cadastro cliente;apagar cadastro medicamentos;consultar um cliente, deve exibir os dados e os medicamentos comprados;
//consultar um medicamento, vai exibir os clientes que compraram;a lista de nome é ordenada por nome;
//e alista de medicamento é ordenada por ID;quando eu remover um cliente ou remedio, nao pode mais aparecer nas consultas de cliente ou mediacamento;
//medicamento{id,nome;quantidade;preço;laboratorio;dosagem;targa;data de validade.}
//cliente{nome;cpf;telefone;tipo sangue;id;email:medicamentoscomprou (10 elementos);
//}
#include <stdio.h>
#include <stdlib.h>
struct medicamento{
	int id,quantMedic;
	char nomeMedic[15],laboratorio[15],tarja[15],validade[15];
	float preco;
	float dosagem;
};

//struct carrinho{
//	int m.id,quant;
//};
struct cliente{
	char nome[15],cpf[15],telefone[15],sangue[2],email[15],medicamentosComprou[10];
};
struct elemento{
	struct cliente cli;
	struct medicamento medic;
	struct elemento *prox;
	struct elemento *anterior;
};

typedef struct elemento *lista;
typedef struct elemento Elem;

lista* criaLista(){
	system("cls");
	lista* li = (lista*) malloc(sizeof(lista));
	
	if(li != NULL){
		*li = NULL;
	}
	
	return li;
}
void listarMed(lista* li){
	system("cls");
	Elem* x = *li;
	
	if(x == NULL){
		printf("Nenhum medicamento no cadastro.\n\n\n");
	}
	while(x != NULL){
		printf("Nome do medicamento:%s\n",x->medic.nomeMedic);
		printf("Nome do laboratorio:%s\n",x->medic.laboratorio);
		printf("Tarja do medicamento:%s\n",x->medic.tarja);
		printf("Validade do medicamento:%s\n",x->medic.validade);
		printf("Preco do medicamento:%.2f\n",x->medic.preco);
		printf("Dosagem do medicamento:%.2f\n",x->medic.dosagem);
		printf("Quantidade do medicamento:%d\n\n\n\n",x->medic.quantMedic);
		x=x->prox;
	}
}
void listarCli(lista* li){
	system("cls");
	Elem* aux = *li;
	
	if(aux == NULL){
		printf("Nenhum cliente no cadastro.\n\n\n");
	}
	while(aux!=NULL){
		printf("Nome do cliente:%s\n",aux->cli.nome);
		printf("Cpf do cliente:%s\n",aux->cli.cpf);
		printf("Telefone do cliente:%s\n",aux->cli.telefone);
		printf("Sangue do cliente:%s\n",aux->cli.sangue);
		printf("Email do cliente:%s\n",aux->cli.email);
		printf("Medicamento do cliente:%s\n\n\n",aux->cli.medicamentosComprou);
		aux = aux->prox;
	}
}
int inserirAlfa(struct cliente c,lista* li){
	system("cls");
	if(li == NULL){
		return 0;
	}
	
	Elem* no = (Elem *)malloc(sizeof(Elem));
	
	if(no == NULL){
		return 0;
	}
	
	no->cli = c;
	
	if((*li) == NULL){
		no->prox = (*li);
		*li = no;
	}else{
		Elem *ant,*atual = *li;
		
		while(atual != NULL && strcmp(atual->cli.nome,c.nome) < 0){
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
int inserirFim(struct medicamento med,lista* li){
	system("cls");
	if(li == NULL){
		return 0;
	}
	
	Elem* node = (Elem*)malloc(sizeof(Elem));
	
	if(node == NULL){
		return 0;
	}
	
	node->medic = med;
	node->prox = NULL;//prepara o nó
	
	if((*li) == NULL){
		*li = node;
	}else{
		Elem *aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = node;
	}
	return 1;
}
lista buscaMed(lista* li){  
	system("cls");
	Elem* aux = *li;                       
//	  **ASSIM COMO NO LISTAR, VC PRECISA CRIAR UM AUXILIAR PARA PASSAR O PONTEIRO DA LISTA, 
//POIS É NA ESTRUTURA ELEM QUE ESTÁ A STRUCT DO MEDICAMENTO;
	char medicamento[15];
	
	if(aux == NULL){ 
        printf("Nenhum cliente cadastrado\n\n\n");
        return 0;
    }
    
	printf("Digite o medicamento para a consulta:");
	fflush(stdin);
	gets(medicamento);
	
	while(aux != NULL && strcmp(aux->medic.nomeMedic, medicamento) != 0){
    	printf("Medicamento não encontrado\n\n\n");
		aux = aux->prox;
	} 
    
    while(aux != NULL && strcmp(aux->medic.nomeMedic, medicamento) == 0){ 
		//VAI PERCORRER TODA LISTA (ENQUANTO NÃO CHEGAR AO FINAL(NULL) E ENQUANTO NÃO ACHAR O NOME IGUAL);
		printf("Nome do medicamento:%s\n",aux->medic.nomeMedic);
		printf("Id do medicamento:%d",aux->medic.id);
		printf("Nome do laboratorio:%s\n",aux->medic.laboratorio);
		printf("Tarja do medicamento:%s\n",aux->medic.tarja);
		printf("Validade do medicamento:%s\n",aux->medic.validade);
		printf("Preco do medicamento:%.2f\n",aux->medic.preco);
		printf("Dosagem do medicamento:%.2f\n",aux->medic.dosagem);
		printf("Quantidade do medicamento:%d\n\n\n\n",aux->medic.quantMedic);
		aux = aux->prox;
    }
    
}
lista busca(lista *li){
	system("cls");
	Elem* aux = *li;
	struct cliente *c;
	char nomeCli[15];
	
	if(aux == NULL){
		printf("Nenhum cliente no cadastro.\n\n\n");
		return 0;
	}
	
	printf("Digite o nome para a busca:\n");
	fflush(stdin);
	gets(nomeCli);
	
	while(aux != NULL && strcmp(aux->cli.nome,nomeCli) != 0){
		printf("Nenhum cliente encontrado com esse nome.\n\n\n");
		aux=aux->prox;
	}
	
	while(aux != NULL && strcmp(aux->cli.nome,nomeCli) == 0){
		printf("Nome do cliente:%s\n",aux->cli.nome);
		printf("Cpf do cliente:%s\n",aux->cli.cpf);
		printf("Telefone do cliente:%s\n",aux->cli.telefone);
		printf("Sangue do cliente:%s\n",aux->cli.sangue);
		printf("Email do cliente:%s\n",aux->cli.email);
		printf("Medicamento do cliente:%s\n\n\n",aux->cli.medicamentosComprou);
		return aux;
		aux=aux->prox;
	}	
 
}
lista *removerCli(lista *li){
	system("cls");
//	Elem *ant;
//	Elem* p =*li;
//	if(li == NULL){
//		printf("Nenhum cliente no cadastro.\n\n\n");
//		return li;
//	}
//	
//	if(p->prox== NULL && p->anterior == NULL){
//		return NULL;
//	}
//	else if(li==p){
//		li = p->prox;
//		li->anterior=NULL;
//	}
//	else if(p->anterior!=NULL && p->prox!=NULL){
//		p->anterior->prox = p->prox;
//		p->prox->anterior = p->anterior;
//	}
//	else if(p->prox == NULL){
//		p->anterior->prox = NULL;
//	}
//	
//	free(p);
//	return li;
	
}
main(){
	struct cliente c;
	struct medicamento m;
	
	int op=0,i,ok;
	char cliDesejado[15];
	lista* li;
	li=criaLista();
	
		
	while(ok==0){
		//	Menu de navegação do programa com opção de sair.
		printf("Bem vindo ao cadastro de cliente e medicamento:\n");
		printf("Digite 1 para cadastrar cliente:\n");//ok
		printf("Digite 2 para listar clientes:\n");//ok
		printf("Digite 3 para remover cliente:\n");
		printf("Digite 4 para buscar cliente:\n");//ok
		printf("Digite 5 para consultar medicamentos comprado pelo cliente:\n\n\n");
		
		printf("Digite 6 para cadastrar medicamento:\n");//ok
		printf("Digite 7 para listar medicamentos:\n");//ok
		printf("Digite 8 para remover medicamento:\n");
		printf("Digite 9 para buscar medicamento:\n");//ok
		printf("Digite 10 para consultar medicamentos:\n");
		printf("Digite 11 para sair:\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				fflush(stdin);
				printf("Informe o nome do cliente:");
				gets(c.nome);
				
				printf("Informe o cpf do cliente:");
				gets(c.cpf);
				
				printf("Informe o telefone do cliente:");
				gets(c.telefone);
				
				printf("Informe o sangue do cliente:");
				gets(c.sangue);
				
				printf("Informe o email do cliente:");
				gets(c.email);
				
				printf("Informe o medicamento do cliente:");
				gets(c.medicamentosComprou);
				inserirAlfa(c,li);
			break;
			
			case 2:
				listarCli(li);
			break;	
			
			case 3:
				//para remover eu primeiro preciso fazer uma busca para saber se o cliente existe
				busca(li);
				li=removerCli(li);
			break;
			
			case 4:
				busca(li);				
			break;
			
			case 5:
			
			break;
				
			case 6:
				fflush(stdin);
				m.id++;
				printf("Informe o nome do medicamento:");
				gets(m.nomeMedic);
				
				printf("Informe o laboratorio do medicamento:");
				gets(m.laboratorio);
				
				printf("Informe o tarja do medicamento:");
				gets(m.tarja);
				
				printf("Informe o validade do medicamento:");
				gets(m.validade);
				
				printf("Informe o preco do medicamento:");
				scanf("%f",&m.preco);
				
				printf("Informe a dosagem do medicamento:");
				scanf("%f",&m.dosagem);
				
				printf("Informe a quantidade do medicamento:");
				scanf("%d",&m.quantMedic);
				
				inserirFim(m,li);
			break;
			
			case 7:
				listarMed(li);
			break;
			
			case 8:
				
			break;
			
			case 9:
				buscaMed(li);
			break;
			
			case 10:
			
			break;
				
			case 11:
				system("cls");
        		printf("Voce pediu para sair, fechando programa...\n");
        		Sleep(3000); // Aqui ele dorme por 3 segundos depois continua o código
				exit(0);
			break;
				
		}
	}
}
