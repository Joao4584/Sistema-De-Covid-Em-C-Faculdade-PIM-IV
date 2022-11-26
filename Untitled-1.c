#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>



int main() {
    char cpfPaciente[12] = {};
    printf("Insira o CPF (somente numeros):\t");
    fgets(cpfPaciente, 12, stdin);
    printf("\n");

    if ((int) cpfPaciente[9] - 48 == calculoCPF1(cpfPaciente)) {
        if ((int) cpfPaciente[10] - 48 == calculoCPF2(cpfPaciente)) {
            printf("CPF VALIDO!\n");
        } else {
            printf("CPF INVALIDO!\n");
        }
    } else {
        printf("CPF INVALIDO!\n");
    }
    return 0;
}
