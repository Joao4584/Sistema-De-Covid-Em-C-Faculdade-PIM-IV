#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

     if(mes>0 && mes<13 && ano>0){


        if((mes==4||mes==6||mes==9||mes==11) && (dia>0 && dia<=30)){

           return 1;

        } else if(mes==2 && (dia>0 && dia<=28)){

           return 1;

        } else if((mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12) && (dia>0 && dia<=31)){

           return 1;

        } else{

           return 0;
        }
        
    }else{
       return 0;
    } 
}

int verificarNumero(int numero){
    
}