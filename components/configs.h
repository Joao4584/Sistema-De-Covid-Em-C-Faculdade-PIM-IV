#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void InitConfigs(){
      system("color 0a");
}

void setColorText(int cor){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
void defaultSetColorText(){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
}