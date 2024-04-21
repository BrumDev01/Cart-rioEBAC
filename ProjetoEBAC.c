#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
    // inicio criação de variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criação de variaveis/string
   
   printf("Digite o CPF a ser cadrastado: \n"); //coletando informação do suário
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf);  //Responsavel por copiar os valores das string
   
   FILE *file; //Cria o arquivo
   file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
   fprintf(file,cpf); //salvo o valor da variavel
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: \n");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: \n");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: \n");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
   
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
      printf("Não foi possivel abrir o arquivo, não localizado!.\n");

    }
   
      while(fgets(conteudo, 200, file) != NULL)
      {
         printf("\nEssas são as informações do usuário: ");
         printf("%s", conteudo);
         printf("\n\n");
       }
       
       system("pause");
       
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado \n");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
     printf("O usuário não se encontra no sistema!.\n");
     system("pause");
    }
}

int main()
{
    int opcao=0; //Defininfo variáveis
    int x=1;
    
    for(x=1;x=1;)
    {
           setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
           
          system("cls");
           
     
          printf("### Cartório da EBAC ###\n\n"); // início do menu
          printf("Escolha a opção desejada do menu:\n\n");
          printf("\t1 - Registrar nomes\n");
          printf("\t2 - Consultar nomes\n");
          printf("\t3 - Deletar  nomes\n\n");
          printf("Opção: "); // fim do menu
          
          scanf("%d", &opcao); // armazenando a escolha usuário
     
          system("cls"); //responsavel por limpar a tela
          
          switch(opcao) //inicio da seleção do menu
          {
            case 1:
            registro(); //chamada de funções
            break;
           
             case 2:
             consulta();
             break;
             
             case 3:
             deletar();
             break;
             
             
             default:
             printf("Essa opção não está disponivel!"); 
             system("pause");
             break;
             
          }
             
}
}       
             
          


