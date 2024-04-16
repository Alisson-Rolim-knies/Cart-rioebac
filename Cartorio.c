#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include<string.h>//biblioteca responsavel por cuidar das string 

int registro() // fun��o responsael por cadastrar os usu�rios no sistema 
{
	//inicio da cria��o de variaveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:  "); //coletando informa��es do usu�rio 
	scanf("%s", cpf); // %s referece as strings salva elas
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo,"w");//cria o arquivo na pasta e o "w" significa escrever.
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file);// fecha o arquivo 
	
	file = fopen (arquivo, "a"); //o "a" � para armazenar mais informa��o nesse caso a ,
	fprintf(file,",CPF:\n"); // aqui esta mandando colocar a virgula 
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:   ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o cargo a ser cargo:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	

	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r para ler o arquivo
	
	if(file == NULL) // comparando com o que tem no banco de dados
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! . \n");
	}
	
	while(fgets(conteudo,200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); 
		
		
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL);
	{
		printf("O usus�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	 
}

int main()
{
	int opcao=0; // Definindo varivaies 
	int x=1;
	
	for (x=1;x=1;)
	
	{
		system("cls"); // responsavel por limpar a tela 
	
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem 
	
		printf("### CART�RIO DA EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar os nomes\n");
		printf("\t3- Deletar nomes\n\n"); // Fim do menu
		printf("opcao:");
	
		scanf("%d", &opcao); // armazenando a escolha do usuario 
	
		system("cls"); // com esse comando limpa a tela 
		
		switch (opcao) //inicio da sele��o do menu
		{
			case 1: 
			registro(); // chamada de fun��o
			break;
			
			case 2:
			consulta(); // chamada de fun��o
			break;
			
			case 3:
			deletar(); // chamada de fun��o
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			//fim da sele��o 
				
		}
	
	}
}
