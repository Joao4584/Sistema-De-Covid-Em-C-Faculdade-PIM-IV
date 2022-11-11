#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"
#include "registrosDeRisco.h"
#include "registrosGerais.h"

// Menu Do Programa
void InitMenu(){

    int option;

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
        RegistrosGeral();
    break;  
    case 3:
        RegistrosDeRisco();
    break;
    case 4:
        system("exit");
    break;          
    default:
        InitMenu();
        break;
    }

}


// Componente Padrao
void voltarMenu(){
    int i;
    printf("\n Cadastro feito com sucesso.\n\n");
    printf(" 1 - Voltar Para O Menu; \n");
    printf(" 2 - Finalizar Sessao; \n");

    printf("Digite uma Opcao:"); scanf("%d", &i);


    if(i == 1){
        system("cls");
        InitMenu();
    }else{
        
        exit(0);
    }


}


