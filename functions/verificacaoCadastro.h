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
