#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"

// Menu Do Programa
void InitMenu(){

    int textC = 135, option;

    TituloPersonalizado("            Painel de Controle            ");

    printf("\n  Menu \n");

    printf("\n  1 - Novo Cadastro de Covid \n");
    printf("  2 - Registros - Cadastros Gerais \n");    
    printf("  3 - Registros - Grupo de Risco \n");
    printf("  4 - Finalizar Sessao \n");
    
    printf("\n  Digite uma opcao: ");
    scanf("%d", &option);
    
    system("cls");
    switch (option){
    case 1:
        NewCadastro();
    break;
    case 2:
        
    break;  
    case 3:
        
    break;
    case 4:
        system("exit");
    break;          
    default:
        InitMenu();
        break;
    }

}

