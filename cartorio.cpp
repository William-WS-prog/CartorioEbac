#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s", cpf); //%s refere-se a string e armazen�las nas vari�veis 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das srtring
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
 	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se a string e armazen�las nas vari�veis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome); //%s refere-se a string e armazen�las nas vari�veis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a string e armazen�las nas vari�veis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	system("pause");
} //Fim da cria��o de vari�veis/string

int consulta()
{
    setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
	char cpf[40];
    char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se a string e armazen�las nas vari�veis
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // R ler arquivo
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, N�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo); //%s refere-se a string e armazen�las nas vari�veis
	printf("\n\n");	
	}
	
	system("pause");

}

int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        perror("Erro ao deletar o arquivo");
    }

    system("pause");
    return 0;
	
}

int main()
    {
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	system("cls"); //responsavel por limpa a tela
	
	setlocale(LC_ALL,"portuguese");//Definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n");// Inicio do menu
	printf("Escolha op��o desejada do menu: \n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opc�o: ");// Fim do menu
	
	scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
	system("cls"); //responsavel por limpa a tela
	
	switch(opcao) // Inicio do sele��o de menu
	{
		case 1:
		registro();	//chamada de fun��es
		break;
		
		case 2:
		consulta(); //chamada de fun��es
		break;
		
		case 3:
		deletar(); //chamada de fun��es		
		break;
		
		case 4:
		printf	("Obrigado por utilizar o sistema");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
    }//fim da sele��o
	
    }

}
