#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    // Dados do Paciente
    int diaNascimento, mesNascimento, anoNascimento;
    char nomePaciente[100], telefonePaciente[20], cpfPaciente[20];

    // Dados de Endereço
     char ruaEndereco[70], bairroEndereco[70], cidadeEndereco[70], estadoEndereco[70];
     int numeroEndereco, CepEndereco;

} cadastro;
cadastro paciente;


void NewCadastro(){

    TituloPersonalizado("            Cadastro De Paciente          ");
    
    ExecNomePaciente();
}

void ExecNomePaciente(){
    int result;

    printf("\n\n Nome do Paciente (Sem Acento):");

    scanf("\n%[^\n]", &paciente.nomePaciente);

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
        
        ExecDataNascimentoPaciente();
    }
 }

void ExecTelefonePaciente(){
    printf("\n Informe o telefone do paciente (11 Digitos):");
    scanf("%d", &paciente.telefonePaciente);

    if(verificarNumero(paciente.telefonePaciente)){
        ExecCpfPaciente();
    }else{
        printf(" Existe um erro no Telefone cadastrado, tente novamente: \n");
        ExecTelefonePaciente();
    }
    

}
void ExecCpfPaciente(){
    printf("\n Informe CPF do paciente:");
    scanf("%d", &paciente.cpfPaciente);
    ExecCamposEndereco();
}

void ExecCamposEndereco(){
    printf("\n ---------------------------------------------\n");
    printf(" Informe o Endereco\n");
    printf(" Estado:"); scanf("\n%[^\n]", &paciente.estadoEndereco);
    printf(" Cidade:"); scanf("\n%[^\n]", &paciente.cidadeEndereco);
    printf(" Bairro:"); scanf("\n%[^\n]", &paciente.bairroEndereco);
    printf(" Rua:"); scanf("\n%[^\n]", &paciente.ruaEndereco);
    printf(" Numero do endereco:"); scanf("%d", &paciente.numeroEndereco);
    printf(" CEP:"); scanf("%d", &paciente.CepEndereco);

    
  
}
 