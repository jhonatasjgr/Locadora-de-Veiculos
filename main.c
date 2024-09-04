#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
	int id;
	char cpf[20];
	char nome[20];
	char rua[20];
	char numero_casa[6];
	char bairro[20];
	char cidade[20];
	char cep[20];
}Cliente;//criei um tipo de variavel que recolhe valores de uma pessoa

typedef struct{
	int id;
	int dis;
	char modelo[20];
	char marca[20];
	char placa[20];
	float valorDiaria;
}Veiculo;//criei um tipo de variavel que recolhe valores de um carro
typedef struct{
	int id;
	int id_clientel;
	int id_veiculol;
	float valorDiaria;
	float dias_locados;
	float preco;
}Locacao;//criei um tipo de variavel que recolhe valores do aluguel de algum carro

Cliente lista_cliente[20];
Veiculo lista_veiculo[20];
Locacao lista_locacao[20];
//declarei os vetores que armazenarão as informações do sistema

int qtd_cliente=0;
int id_cliente=0;
int qtd_veiculo=0;
int id_veiculo=0;
int qtd_locacao=0;
int id_locacao=0;
//declarei variaveis globais que serão usadas em todo o programa

void cadastrar_cliente(){
	id_cliente++;
	char temp;//limpar o buffer de memória
	lista_cliente[qtd_cliente].id=id_cliente;
	printf("Cadastrar cliente\n");
	printf("Nome: ");
	scanf("%c", &temp);
    scanf("%[^\n]", lista_cliente[qtd_cliente].nome);
	printf("CPF: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].cpf);
	printf("Rua: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].rua);
	printf("Numero da casa: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].numero_casa);
	printf("Bairro: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].bairro);
	printf("Cidade: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].cidade);
	printf("CEP: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[qtd_cliente].cep);
	qtd_cliente++;
	printf("\nCliente Salvo com sucesso!!\nID do cliente: %d\n", id_cliente);
	//função de cadastro do cliente
}
void listar_cliente(){
	int i;
	for ( i=0; i<qtd_cliente; i++){
		printf("Nome: %s\nID: %d\n", lista_cliente[i].nome, lista_cliente[i].id);
	}
	//função para listar todos os clientes cadastrados
}
int pesquisar(int id){
	int i=0;
    for ( i=0; i<qtd_cliente; i++){
        if(id == lista_cliente[i].id){
            return i;
        }
    }
    return -1;
    //função de operação de busca comparando valores
}
void pesquisar_cliente(){
	int id;
	printf("Digite o ID do cliente: ");
	scanf("%d", &id);
	int pos=pesquisar(id);
	if(pos!=-1){
		printf("\nCLIENTE\nNome:%s\nCPF:%s\n", lista_cliente[pos].nome, lista_cliente[pos].cpf);
		printf("===ENDEREÇO===\n");
		printf("Rua:%s\nNumero:%s\nBairro:%s\nCidade:%s\nCEP:%s\n", lista_cliente[pos].rua, lista_cliente[pos].numero_casa, lista_cliente[pos].bairro, lista_cliente[pos].cidade, lista_cliente[pos].cep);
	}else{
		printf("Cliente não encontrado.\n");
	}
	//função para pesquisar um cliente
}
void excluir_cliente(){
	int id;
	printf("Digite o ID do cliente que deseja excluir:");
	scanf("%d", &id);
	int pos=pesquisar(id);
	if(pos!=-1) {
		lista_cliente[pos]=lista_cliente[qtd_cliente-1];
		qtd_cliente--;
		printf("Cliente exluido com sucesso.");
} else {
		printf("Cliente não encontrado.");
	}
	//função para excluir um cliente cadastrado
}
void atualizar_cliente(){
	int id;
	char temp;
	printf("Digite o ID do cliente que deseja atualizar os dados:");
	scanf("%d", &id);
	int pos=pesquisar(id);
	if(pos!=-1){
	printf("Nome: ");
	scanf("%c", &temp);
    scanf("%[^\n]", lista_cliente[pos].nome);
	printf("CPF: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].cpf);
	printf("Rua: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].rua);
	printf("Numero da casa: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].numero_casa);
	printf("Bairro: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].bairro);
	printf("Cidade: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].cidade);
	printf("CEP: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_cliente[pos].cep);
	printf("\nDados do Cliente atualizado com sucesso!!");
	}else{
		printf("Cliente não encontrado");
	}
	//função para atualizar os dados cadastrais do cliente
}
void cadastrar_veiculo(){
	char temp;
	id_veiculo++;
	lista_veiculo[qtd_veiculo].id=id_veiculo;
	printf("Marca do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[qtd_veiculo].marca);
	printf("Modelo do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[qtd_veiculo].modelo);
	printf("Placa do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[qtd_veiculo].placa);
	printf("Valor da diaria: ");
	scanf("%f", &lista_veiculo[qtd_veiculo].valorDiaria);
	lista_veiculo[qtd_veiculo].dis=1;
	qtd_veiculo++;
	printf("Veiculo cadastrado com sucesso");
	//função para cadastrar o veiculo
}
void listar_veiculo(){
	int i;
	for(i=0; i<qtd_veiculo; i++){
		printf("ID: %d\nMARCA: %s\nMODELO: %s\nPLACA: %s \n", lista_veiculo[i].id, lista_veiculo[i].marca, lista_veiculo[i].modelo, lista_veiculo[i].placa);
	}
	//função para listar todos os veiculos cadastrados 
}
int pesquisar2(int id){
	int i=0;
    for ( i=0; i<qtd_veiculo; i++){
        if(id == lista_veiculo[i].id){
            return i;
        }
    }
    return -1;
    //função para fazer uma operação busca atraves de comparação
}
void pesquisar_veiculo(){
	int id;
	printf("Digite o ID do veiculo: ");
	scanf("%d", &id);
	int pos=pesquisar2(id);
	if(pos!=-1){
		printf("\nMARCA: %s\nMODELO:%s\nPLACA:%s\n", lista_veiculo[pos].marca, lista_veiculo[pos].modelo, lista_veiculo[pos].placa);
	}else{
		printf("Veiculo não encontrado.\n");
	}
	//função para fazer a busca de um veiculo especifico
}
void excluir_veiculo(){
	int id;
	printf("Digite o ID do veiculo que deseja excluir:");
	scanf("%d", &id);
	int pos=pesquisar2(id);
	if(pos!=-1) {
		lista_veiculo[pos]=lista_veiculo[qtd_veiculo-1];
		qtd_veiculo--;
		printf("Veiculo exluido com sucesso.");
} else {
		printf("Veiculo não encontrado.");
	}
	//função para excluir veiculo
}
void atualizar_veiculo(){
	int id;
	char temp;
	printf("Digite o ID do Veiculo que deseja atualizar os dados:");
	scanf("%d", &id);
	int pos=pesquisar2(id);
	if(pos!=-1){
	lista_veiculo[qtd_veiculo].id=id_veiculo;
	printf("Marca do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[pos].marca);
	printf("Modelo do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[pos].modelo);
	printf("Placa do veiculo: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lista_veiculo[qtd_veiculo].placa);
	printf("Diaria do veiculo: ");
	scanf("%f", &lista_veiculo[pos].valorDiaria);
	printf("Veiculo atualizado com sucesso");
}else{
		printf("Veiculo não encontrado");
	}
	//função para para atualizar os dados de um veiculo
}
float multiplica(float n1, float n2){
	float resultado=n1*n2;
	return(resultado);
	//função para realizar o calculo de preço final da locação
}
void cadastrar_locacao(){
	char temp;
	id_locacao++;
	int cont=0;
	lista_locacao[qtd_locacao].id=id_locacao;
	printf("Digite o ID do cliente que deseja alugar um veiculo: ");
	scanf("%d", &lista_locacao[qtd_locacao].id_clientel);
	int i;
	float dcs, dias;
	int comeco=0;
	for(i=0; i<qtd_veiculo; i++){
		if(lista_veiculo[i].dis==1){
			if(lista_veiculo[i].dis){
				printf("\nNÃO TEMOS VEICULOS DISPONIVEIS\n");
			}
		printf("ID: %d\nMARCA: %s \nMODELO: %s \n", lista_veiculo[i].id, lista_veiculo[i].marca, lista_veiculo[i].modelo);
		cont++;
		}else{
			printf("A LOCADORA NÃO TEM VEICULOS DISPONIVEIS\n");
		}
	}
	if(cont>0){
	printf("Digite o ID do veiculo que deseja alugar: ");
	scanf("%d", &lista_locacao[qtd_locacao].id_veiculol);
	int posi=pesquisar2(lista_locacao[qtd_locacao].id_veiculol);
	if(posi>-1){
	lista_veiculo[posi].dis=0;
	dcs=lista_veiculo[posi].valorDiaria;
	printf("Por quantos dias deseja alocar o veiculo?: ");
	scanf("%f", &dias);
	float precof=multiplica(dias, dcs);
	lista_locacao[qtd_locacao].preco = precof;
	printf("\nA locação custará R$%.2f \n", precof);
	qtd_locacao++;}
	}else{
		printf("\nNÃO TEMOS VEICULOS DISPONIVEIS\n");
	}
	//função para cadastrar locação
}
void devolucao(){
	int i;
	int devolucao, pag;
	if(qtd_locacao>0){
	
	printf("LOCAÇÕES FEITAS\n");
	for(i=0; i<qtd_locacao; i++){
		printf("ID locação: %d\nID Cliente: %d\nID Veiculo: %d\n", lista_locacao[i].id, lista_locacao[i].id_clientel, lista_locacao[i].id_veiculol);
		}
	printf("Digite a locação que deseja devolver: ");
	scanf("%d", &devolucao);
	printf("O pagamento foi feito pelo cliente?:\n1-SIM\n2-NÃO");
	scanf("%d", &pag);
	if(pag==1){
	int poss=pesquisar2(lista_locacao[devolucao].id_veiculol);
	lista_veiculo[poss].dis=1;
	qtd_locacao--;}
}
//função para devolução do veiculo
}
void menu_cliente(){
	printf("\n\n======MENU_CLIENTE======");
	printf("\n1-CADASTRAR\n2-LISTAR\n3-PESQUISAR\n4-ATUALIZAR\n5-EXCLUIR\n6-VOLTAR AO MENU PRINCIPAL\nOPÇÃO: ");
	int op;
	scanf("%d", &op);
	printf("==========================\n");
	switch(op){
		case 1:
			cadastrar_cliente();
			menu_cliente();
			break;
		case 2:
			listar_cliente();
			menu_cliente();
			break;
		case 3:
			pesquisar_cliente();
			menu_cliente();
			break;
		case 4:
			atualizar_cliente();
			menu_cliente();
			break;
		case 5:
			excluir_cliente();
			menu_cliente();
			break;
		case 6:
			break;
		default:
			system("cls");
			menu_cliente();
	}
	
}
void menu_veiculo(){
	printf("\n\n======MENU VEICULO======");
	printf("\n1-CADASTRAR\n2-LISTAR\n3-PESQUISAR\n4-ATUALIZAR\n5-EXCLUIR\n6-VOLTAR AO MENU PRINCIPAL\nOPÇÃO: ");
	int op;
	scanf("%d", &op);
	printf("==========================\n");
	switch(op){
		case 1:
			cadastrar_veiculo();
			menu_veiculo();
			break;
		case 2:
			listar_veiculo();
			menu_veiculo();
			break;
		case 3:
			pesquisar_veiculo();
			menu_veiculo();
			break;
		case 4:
			atualizar_veiculo();
			menu_veiculo();
			break;
		case 5:
			excluir_veiculo();
			menu_veiculo();
			break;
		case 6:
		break;
		default:
			menu_veiculo();
			break;
	}
	
}
void menu_locacao(){
	cadastrar_locacao();
	}
void menu_principal(){
	int op;
	printf("\n===MENU PRINCIPAL===");
	printf("\n1-CLIENTE\n2-VEICULO\n3-LOCAÇÃO\n4-DEVOLUÇÃO\n5-SAIR\nOPÇÃO: ");
	scanf("%d", &op);
	printf("========================\n");
	switch(op){
		case 1:
			system("cls");
			menu_cliente();
			system("cls");
			menu_principal();
			break;
		case 2:
			system("cls");
			menu_veiculo();
			system("cls");
			menu_principal();
			break;
		case 3:
			menu_locacao();

			menu_principal();
			system("cls");
			break;
		case 4:
			devolucao();
			system("cls");
			menu_principal();
			system("cls");
			break; 
		case 5:
			break;
		default:
			if(op!=1||op!=2||op!=3||op!=4||op!=5||op!=0){
				menu_principal();
			}
			break;
	}
}
int main(int argc, char *argv[]) {
	menu_principal();
	return 0;
}