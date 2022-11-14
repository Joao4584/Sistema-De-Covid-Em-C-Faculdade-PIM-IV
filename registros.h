#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrosDeRisco(){
    printf(" Registro contem os seguintes dados: \n");
       FILE *files;
      files = fopen("grupoDeRisco.txt", "r");

      if(files == 0){
       printf(" Nenhum Cadastro Encontrado... \n");
      }

       char frase[100];

       while(fgets(frase, 100, files) != 0){
       
        printf("%s\n", frase);
       }

       fclose(files);
      printf("\n=================================\n");

        menuRegistroRisco();
       
}

void menuRegistroRisco(){
   int i;
        printf("\n 1 - Limpar Dados Do Arquivo; \n");
        printf(" 2 - Voltar Para O Menu; \n\n");

        printf("Digite uma Opcao:"); scanf("%d", &i);


        if(i == 1){
           FILE *files;
           files = fopen("grupoDeRisco.txt", "w");
           printf("Todos excluidos com Exito!\n");   
           fclose(files);
           voltarMenu();
        }else if(i == 2){
             system("cls");
             InitMenu();
        }else{
          printf(" Nao encontrado, tente novamente; \n");
          menuRegistro();
        }
}

void RegistrosGeral(){
    printf(" Registro contem os seguintes dados: \n");
    FILE *files;
      files = fopen("todosCadastros.txt", "r");

      if(files == 0){
       printf(" Nenhum Cadastro Encontrado... \n");
      }

       char frase[100];

       while(fgets(frase, 100, files) != 0){
       
        printf("%s\n", frase);
       }

       fclose(files);
       printf("\n=================================\n");

        menuRegistro();
       
}

void menuRegistro(){
   int i;
        printf(" 1 - Limpar Dados Do Arquivo; \n");
        printf(" 2 - Voltar Para O Menu; \n\n");

        printf("Digite uma Opcao:"); scanf("%d", &i);


        if(i == 1){
           FILE *files;
           files = fopen("todosCadastros.txt", "w");
           printf("Todos excluidos com Exito!\n");   
           fclose(files);
           voltarMenu();
        }else if(i == 2){
             system("cls");
             InitMenu();
        }else{
          printf(" Nao encontrado, tente novamente; \n");
          menuRegistro();
        }
}