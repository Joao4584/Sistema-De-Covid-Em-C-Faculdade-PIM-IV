#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "verificacaoCadastro.h"
#include "menu.h"

typedef struct {
    char login[30];
    char senha[30];
} pessoa;
pessoa p[1];

void main(void){
    // Configurations
       system("color 0a");
    // Init System
      InicioDeLogin();
}

// Executa o sistema de login
void InicioDeLogin(){
   
    char login[30];
    char senha[30];
    
    strcpy(p[0].login, "unip");
    strcpy(p[0].senha, "1234");

    TituloPersonalizado("          SISTEMA DE COVID - UNIP         ");

    printf("\n  Autenticacao de Usuario \n\n");

    printf("  Login do usuario:");
    scanf("%s", &login);
    printf("\n  Senha do usuario:");
    scanf("%s", &senha);

    // Verificação De Login E Senha
    if ((strcmp(login, p[0].login) == 0 && (strcmp(senha, p[0].senha) == 0))){
        system("cls");
        InitMenu();
    }else{
        SenhaIncorreta();
    }
}

// Se a senha estiver incorreta executa o sistema
void SenhaIncorreta(){
    system("cls");
    
    TituloPersonalizado("         Senha ou Login Incorretos..      ");

    int opcao;

    printf("\n\n  1 - Tentar Novamente \n");
    printf("  2 - Finalizar Sessao \n \n");
    printf("  Digite uma opcao: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        system("cls");
        main();
    }else if(opcao == 2){
        system("exit");
    }else{
        SenhaIncorreta();
    }

}


// Definicao de topo para as paginas
void TituloPersonalizado(char titulo[]){
     int bar = 196, barColum = 179, position;
     printf(" ");
     for (position = 0; position <= 45; position++){
        switch(position){
            case 0:
                printf("%c", 218);
            break;
            case 45:
                printf("%c\n", 191);
            break;
            default:
                printf("%c", bar);
        }
     }
     printf(" %c %s %c\n", barColum, titulo, barColum);
     printf(" ");
     for (position = 0; position <= 45; position++){
        switch(position){
            case 0:
                printf("%c", 192);
            break;
            case 45:
                printf("%c\n", 217);
            break;
            default:
                printf("%c", bar);
        }
     }
}





