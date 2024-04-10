#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de criação de strings

int registrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia valores de uma string para outra
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" escreve a informação
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
		
    system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //define linguagem para usar acentos
	
	char cpf[40];
	char conteudo[200];
	
	printf("Informe o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não encontrado! \n");
	}
		printf("\nInformações da consulta: ");
		printf("\nCPF: ");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		// printf("\nInformações da consulta:");
		printf("%s", conteudo);
		//printf("\n");
	}
	system("pause");
	fclose(file);
		
}

int apagar()
{
	char cpf[40];
	
	printf("Digite o CPF a se excluído:");
	scanf("%s", cpf);
	remove(cpf);
	printf("\nCPF excluído com sucesso!");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n\nCPF não cadastrado!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("--- Cartório EBAC ---\n\n"); //início do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n") ;
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //para limpar a tela
		
		switch(opcao)
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			apagar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0; // quebra de laço e saida do sistema
			break;
			
			default:
			printf("Opção indisponível\n");	
			system("pause");
			break;
		}
	}
	
		
}
