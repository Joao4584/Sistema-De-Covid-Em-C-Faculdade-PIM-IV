#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    // Dados do Paciente
    int diaNascimento, mesNascimento, anoNascimento, possuiComorbidade;
    char nomePaciente[100], telefonePaciente[20], cpfPaciente[20], emailPaciente[100], comorbidadePaciente[50];

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

// ! Walef
void ExecTelefonePaciente(){
    printf("\n Informe o telefone do paciente (11 Digitos):");
    scanf("%s", &paciente.telefonePaciente);

    if(verificarNumero(paciente.telefonePaciente)){
        ExecEmailPaciente();
    }else{
        printf(" Existe um erro no Telefone cadastrado, tente novamente: \n");
        ExecTelefonePaciente();
    }
}

void ExecEmailPaciente(){
    printf("\n Informe o Email Do Paciente (exemplo@exemplo.com):");
    scanf("\n%[^\n]", &paciente.emailPaciente);

    if(verificarEmail(paciente.emailPaciente)){
        ExecCpfPaciente();
    }else{
        printf(" Email Invalido, Tente Novamente: \n");
        ExecEmailPaciente();
    }



    
}

// ! Walef
void ExecCpfPaciente(){
    printf("\n Informe CPF do paciente:");
    scanf("%s", &paciente.cpfPaciente);
    ExecComorbidades();

    //   if(verificarEmail(paciente.emailPaciente)){
    //    ExecComorbidades();
    // }else{
    //     printf(" Email Invalido, Tente Novamente: \n");
    //     ExecEmailPaciente();
    // }
}


void ExecComorbidades(){
    printf("\n O Paciente possui comorbidades? (Digite 1 para sim e 0 para nao): ");
    scanf("%d", &paciente.possuiComorbidade);

    if(paciente.possuiComorbidade == 1){
        printf("\n Que Comorbidades?: ");
        scanf("\n%[^\n]", &paciente.comorbidadePaciente);
        ExecCamposEndereco();

    }else if(paciente.possuiComorbidade == 0){
            ExecCamposEndereco();
    }else{
        printf("Opcao nao encontrada, tente novamente: \n");
        ExecComorbidades();
    }
}


// ! Pendente
void ExecCamposEndereco(){
    printf("\n ---------------------------------------------\n");
    printf(" Informe o Endereco\n");
    printf(" Estado:"); scanf("\n%[^\n]", &paciente.estadoEndereco);
    printf(" Cidade:"); scanf("\n%[^\n]", &paciente.cidadeEndereco);
    printf(" Bairro:"); scanf("\n%[^\n]", &paciente.bairroEndereco);
    printf(" Rua:"); scanf("\n%[^\n]", &paciente.ruaEndereco);
    printf(" Numero do endereco:"); scanf("%d", &paciente.numeroEndereco);
    printf(" CEP:"); scanf("%d", &paciente.CepEndereco);

    SalvandoCadastro();

}




// Salvando Dados No Txt
void SalvandoCadastro(){
    FILE *file;
    file = fopen("todosCadastros.txt", "a");

      if(file == 0){
        file = fopen("todosCadastros.txt", "w");
        printf("Criando Arquivo... \n");
        SalvandoCadastro();
      }
   
      fprintf(file, "==============================================\n");
      fprintf(file, " - Dados Pessoais\n");
      fprintf(file, " Nome Do Paciente: %s;\n", paciente.nomePaciente);
      fprintf(file, " Data De nascimento: %d/%d/%d;\n", paciente.diaNascimento, paciente.mesNascimento, paciente.anoNascimento);
      fprintf(file, " Telefone: %s;\n", paciente.telefonePaciente);
      fprintf(file, " CPF: %s;\n", paciente.cpfPaciente);
      fprintf(file, " Email: %s;\n", paciente.emailPaciente);
      if(paciente.possuiComorbidade == 0){
        fprintf(file, " Comorbidade: Nao tem;\n\n");
      }else{
        fprintf(file, " Comorbidade: %s;\n\n", paciente.comorbidadePaciente);
      }
      fprintf(file, " - Endereço Do Paciente\n\n");
      fprintf(file, " Estado: %s\n", paciente.estadoEndereco);
      fprintf(file, " Cidade: %s\n", paciente.cidadeEndereco);
      fprintf(file, " Bairro: %s\n", paciente.bairroEndereco);
      fprintf(file, " Rua: %s\n", paciente.ruaEndereco);
      fprintf(file, " Numero: %d\n", paciente.numeroEndereco);
      fprintf(file, " CEP: %d\n", paciente.CepEndereco);

      SYSTEMTIME str_t;
      GetSystemTime(&str_t);
      
      int anoAtual = str_t.wYear;
      int mesAtual = str_t.wMonth;
      int diaAtual = str_t.wDay;

      fprintf(file, "\n Data do Diagnostico: %d/%d/%d ;\n", diaAtual, mesAtual, anoAtual);

      fclose(file);

    
      int idadeAtual = anoAtual - paciente.anoNascimento;
      if(idadeAtual >= 65 || paciente.possuiComorbidade == 1){
    	printf(" Diagnosticado como grupo de risco, criando arquivo.. \n");
        SalvandoCadastroDeRisco(idadeAtual);
      }else{
        voltarMenu();
      }

}

void SalvandoCadastroDeRisco(int idadeAtual){
      FILE *files;
      files = fopen("grupoDeRisco.txt", "a");

      if(files == 0){
        files = fopen("grupoDeRisco.txt", "w");
        printf(" Criando Arquivo... \n");
        SalvandoCadastro();
      }else{
        printf(" Adicionando Dados ao Arquivo Do Grupo de Risco... \n");
      }

       fprintf(files, "==============================================\n");
       fprintf(files, " CEP: %d - Idade: %d anos. \n", paciente.CepEndereco, idadeAtual);


       fclose(files);
       
       voltarMenu();

}



 