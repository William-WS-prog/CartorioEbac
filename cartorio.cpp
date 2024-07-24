#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s", cpf); //%s refere-se a string e armazenálas nas variáveis 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das srtring
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
 	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //%s refere-se a string e armazenálas nas variáveis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome); //%s refere-se a string e armazenálas nas variáveis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informações do usuário
	scanf("%s",cargo); //%s refere-se a string e armazenálas nas variáveis
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file,cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // acessa arquivo que ja existe
    fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	system("pause");
} //Fim da criação de variáveis/string

int consulta()
{
    setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
	char cpf[40];
    char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se a string e armazenálas nas variáveis
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // R ler arquivo
	
	if(file == NULL)
	{
	printf("Não foi possivel abrir o arquivo, Não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo); //%s refere-se a string e armazenálas nas variáveis
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
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	system("cls"); //responsavel por limpa a tela
	
	setlocale(LC_ALL,"portuguese");//Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n");// Inicio do menu
	printf("Escolha opção desejada do menu: \n\n");
	printf("\t1 - Registra nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opcão: ");// Fim do menu
	
	scanf("%d", &opcao);//armazenando a escolha do usuário
	
	system("cls"); //responsavel por limpa a tela
	
	switch(opcao) // Inicio do seleção de menu
	{
		case 1:
		registro();	//chamada de funções
		break;
		
		case 2:
		consulta(); //chamada de funções
		break;
		
		case 3:
		deletar(); //chamada de funções		
		break;
		
		case 4:
		printf	("Obrigado por utilizar o sistema");
		return 0;
		break;
		
		default:
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
    }//fim da seleção
	
    }

}
