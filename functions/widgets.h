#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void divisaoPersonalizada(){
    
     int bar = 196, position;

     printf(" ");
     for (position = 0; position <= 45; position++){
         printf("%c", bar);
     }
     printf("\n");

}