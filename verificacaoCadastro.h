#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

int verificarLetras(char *palavras){
   
   int i;
   for(i=0; palavras[i] != '\0'; i++){
    if(palavras[i] != ' '){
        if(!isalpha(palavras[i])){
            
            // Se a string tiver caracter ou numero
            return 0;
        }
    }
   }


   // Se o Texto Conter somente string

   return 1;

} 

int verificarData(int mes, int dia, int ano){
      SYSTEMTIME str_t;
      GetSystemTime(&str_t);
      int anoAtual = str_t.wYear;

      if(ano > 1900 && ano < anoAtual){
            if(mes>0 && mes<13 && ano>0){


                  if((mes==4||mes==6||mes==9||mes==11) && (dia>0 && dia<=30)){

                     return 1;

                  } else if(mes==2 && (dia>0 && dia<=28)){

                     return 1;

                  } else if((mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12) && (dia>0 && dia<=31)){

                     return 1;

                  } else{
                     printf(" Existe um erro na data cadastrada, tente novamente: \n");
                     return 0;
                  }
                  
               }else{
                  printf(" Existe um erro na data cadastrada, tente novamente: \n");
                  return 0;
               } 
      }else{
         printf(" Existe um erro no ano marcado, tente novamente: \n");
         return 0;
      }

    
}

int verificarNumero(char *numero){

   int i;
    int count = 0; 
    
    
   for (count = 0; numero[count] != '\0'; ++count);


   if(count != 11){
   
      return 0;
   }else{

      for (i = 0; numero[i] != '\0'; i++){
         if (numero[i] != ' ')
         {
            if (isalpha(numero[i]))
            {
               return 0;
            }
         }
      }

      // Se o Texto Conter somente string

      return 1;
   }
}


int verificaCEP(char *numero){

   int i;
    int count = 0; 
    
    
   for (count = 0; numero[count] != '\0'; ++count);


   if(count != 8){
      printf("O CEP nao contem o numero de digitos correto (8 digitos), preencha novamente; \n\n");
      return 0;

   }else{

      for (i = 0; numero[i] != '\0'; i++){
         if (numero[i] != ' ')
         {
            if (isalpha(numero[i]))
            {
               return 0;
            }
         }
      }

      // Se o Texto Conter somente string

      return 1;
   }
}

int verificaContemNumero(char *numero){

   int i;
   
      for (i = 0; numero[i] != '\0'; i++){
         if (numero[i] != ' ')
         {
            if (isalpha(numero[i]))
            {
               printf("O Campo  Numero De Endereco contem caracteres de texto \n\n");
               return 0;
            }
         }
      }

      // Se o Texto Conter somente string

      return 1;
 
}




int verificarEmail(char *email){
   int i;
   int tam = strlen(email);
   int arroba = 0;

   for (i = 0; i < tam; i++){
      
      if (email[i] == '@'){
         if (arroba == 0){
            arroba = 1;
         }else if(arroba > 0) {
            arroba = 10;
            break;
         }
      }
   }

   if(arroba == 0 || arroba == 10){
      return 0;
   }else{
      return 1;
   }

}


// Verificação de CPF
int calculoCPF1(char cpf[11]) {

    int calculoCPF1(char cpf[12]);
    int calculoCPF2(char cpf[12]);

    int soma = 0, i = 10;
    char *ptr = cpf;

    while (i > 1) {
        int n = (int) *ptr - 48;
        soma = soma + i * n;
        ptr++;
        i--;
    }

    if (soma % 11 < 2) {
        return 0;
    } else {
        return 11 - (soma % 11);
    }
}

int calculoCPF2(char cpf[11]) {
    int soma = 0, i = 11;
    char *ptr = cpf;

    while (i > 1) {
        int n = (int) *ptr - 48;
        soma = soma + i * n;
        ptr++;
        i--;
    }

    if (soma % 11 < 2) {
        return 0;
    } else {
        return 11 - (soma % 11);
    }
}
