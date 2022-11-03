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

    
    
 }

 


