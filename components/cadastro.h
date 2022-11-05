#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    // Dados do Paciente
    int telefonePaciente, cpfPaciente, diaNascimento, mesNascimento, anoNascimento;
    char nomePaciente[100];

    // Dados de Endereço
     char ruaEndereco[70], bairroEndereco[70], cidadeEndereco[70], estadoEndereco[70];
     int numeroEndereco, CepEndereco;

} cadastro;
cadastro paciente;


void NewCadastro(){

    TituloPersonalizado("            Cadastro De Paciente          ");
    
    ExecNomePaciente();
}

 int ExecNomePaciente(){
    int result;

    printf("\n\n Nome do Paciente (Sem Acento):");

    scanf("%s", &paciente.nomePaciente);

    if(verificarLetras(paciente.nomePaciente)){
        ExecDataNascimentoPaciente();
    }else{
        printf("\n Contem numeros ou caracteres especiais em seu nome, tente novamente");
        ExecNomePaciente();
    } 
    
 }

void ExecDataNascimentoPaciente(){
     printf("\n Coloque sua data de nascimento:");

     printf("\n Dia (XX): ");
        scanf("%d", &paciente.diaNascimento);
     printf(" Mes (XX): ");
        scanf("%d", &paciente.mesNascimento);
     printf(" Ano (XXXX): ");
        scanf("%d", &paciente.anoNascimento);

    if(verificarData(paciente.mesNascimento, paciente.diaNascimento, paciente.anoNascimento)){
        ExecTelefonePaciente();
    }else{
        printf(" Existe um erro na data cadastrada, tente novamente: \n");
        ExecDataNascimentoPaciente();
    }
 }

void ExecTelefonePaciente(){
    printf("\n Informe seu telefone (11 Digitos):");
    scanf("%d", &paciente.telefonePaciente);

    

}
void ExecCpfPaciente(){
    
}

 


