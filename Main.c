#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Nm =0;//Numero de médicos
int Np =0;//Numero de pacientes
int Nc =0;//Numero de consultas

typedef struct {
  char usuario[20];
  char senha[10];
} login;

typedef struct {
  char CRM[6];
  char Nome[50];
  char DataNascimento[10]; // formato dd/mm/aaaa
  char Especialidade[20];
  float salarioHora;
  char telefone[11];
} medico;

typedef struct {
  char CPF[11];
  char Nome[50];
  char DataNascimento[10]; // formato dd/mm/aaaa
  char Telefone[11];
} paciente;

typedef struct {
  char CRM_Medico[6];
  char CPF_pasciente[11];
  char Data[10]; // formato dd/mm/aaaa
  char Sintomas[100];
  char Encaminhamentos[100];
} consulta;

void menu(int N) {
printf("Escolha a opcao\n\nEfetuar login (1)\n\nCadastrar Usuario ""(2)\n\nEncerrar programa(0)");
}
void menu_logado(){
printf("\nO que deseja fazer? Digite a opcao Desejada:\n Acessar Medicos cadastrados(1)\n Acessar pacientes cadastrados(2)\n Acessar consultas registradas(3)\nCadastrar médicos(4)\nSair do Programa (0)\n");
}
void CadastroM(medico *vetor) {
    printf("\nDigite o CRM\n");
    scanf("%s%*c", vetor[Nm].CRM);

    printf("\nDigite o cpf\n");
    scanf("%s%*c", vetor[Nm].Nome);

    printf("\nDigite a data de nascimento\n");
    scanf("%s%*c", vetor[Nm].DataNascimento);

    printf("\nDigite a especialidade\n");
    scanf("%s%*c", vetor[Nm].Especialidade);

    printf("\nDigite o salario\n");
    scanf("%f%*c", &vetor[Nm].salarioHora);

    printf("\nDigite o Telefone\n");
    scanf("%s%*c", vetor[Nm].telefone);

    Nm++;
  }


void CadastroL(int *quant_login) {
  char confirm[20];
  login vetor;
  // Abrindo o arquivo de login
  FILE *archive_p;
  archive_p = fopen("login.bin", "ab");
  if (archive_p != NULL) {
    printf("n\nArquivo binario.bin foi aberto com sucesso\n");
  } else {
    printf("\n\nErro: O arquivo binario.bin não foi aberto\n");
    system("pause");
    exit(0);
  }
  // jogando as informaçÕes para dentro da struct declarada(RAM)
  printf("\nDigite o usuario: \n");
  scanf("%s%*c", vetor.usuario);
  printf("\nDigite a senha: \n");
  scanf("%s%*c", vetor.senha);
  printf("\nConfirme a senha\n");
  scanf("%s%*c", confirm);
  if (strcmp(vetor.senha, confirm) == 0) {
    printf("\nCadastro concluido");
    *quant_login += 1;
  } else {
    printf("\nAs senhas nao coincidem, digite as informacoes novamente");
  }
  // Salvando no arquivo
  fwrite(&vetor, sizeof(login), 1, archive_p);
  if (ferror(archive_p)) {
    printf("\nNOTICIA RUIM\n");
  } else {
    printf("\nOK\n");
  };
  fclose(archive_p);
  printf("%d", *quant_login);
  system("pause");
}

int Login(login *vetor, int *quant_login) {
  // Abrindo o arquivo de login
  FILE *archive_p;
  archive_p = fopen("login.bin", "rb");
  if (archive_p != NULL)
    printf("n\nArquivo binario.bin foi aberto com sucesso\n");
  else {
    printf("\n\nErro: O arquivo binario.bin não foi aberto\n");
    system("pause");
    exit(0);
  }
  fread(vetor, sizeof(login), *quant_login, archive_p);

  char usuario[20], senha[10];
  for (int j = 0; j < 3; j++) {
    printf("Digite o nome de usuario");
    scanf("%s%*c", usuario);
    printf("Digite a senha");
    scanf("%s%*c", senha);
    for (int i = 0; i < *quant_login; i++) {
      if (strcmp(usuario, vetor[i].usuario) == 0 &&
          strcmp(senha, vetor[i].senha) == 0) {
        printf("\n login feito com sucesso");
        fclose(archive_p);
        return 1;
      }
    }
  }
  printf("\n Houveram muitas tentativas de login erradas, tente novamente");
  fclose(archive_p);
}

void funcao_busca_info(medico *M, int quant_medicos) {
  int y;
  // ordenador(M, quant_medicos); // Ordenação em ordem alfabética dos
  // vendedores.
  char medicoInteresse[60];
  printf("\nDigite qual o medico de seu interesse:");
  scanf("%[^\n]%*c", medicoInteresse);
  // y = busca_binaria(V, medicoInteresse, quant_medicos);
  if (y == -1) {
    return;
  } else {
    printf("vendedor %d\n\n", y + 1);

    printf("Nome: %s\n", M[y].Nome);

    printf("CRM: %s \n", M[y].CRM);

    printf("data de nascimento: %s \n", M[y].DataNascimento);

    printf("salario hora: %2.f\n", M[y].salarioHora);

    printf("Especialidade: %s\n", M[y].Especialidade);

    printf("telefone: %s\n", M[y].telefone);
  }
}
// Busca binaria necesária

void main() {
// Abrindo o arquivo de login
  FILE *archive_p;
  archive_p = fopen("contadores.bin", "rb");
  if (archive_p != NULL)
    printf("n\nArquivo binario.bin foi aberto com sucesso\n");
  else {
    printf("\n\nErro: O arquivo binario.bin não foi aberto\n");
    system("pause");
    exit(0);
  }


  int quant_login = 0;
  login *L;
  L = (login *)malloc(1 * sizeof(login));

  medico *M;
  M = (medico *)malloc(1 * sizeof(medico));
  int N_medicos = 0;

  paciente *P;
  P = (paciente *)malloc(1 * sizeof(paciente));

  consulta *C;
  C = (consulta *)malloc(1 * sizeof(consulta));

  int x = 3;
  int escolha;

  while (x != 0) {
    menu(1);

    scanf("%d", &x);

    if (x == 1) {
    if(Login(L,&quant_login) ==1){
    menu_logado();
    }
    }
    if (x == 2) {
CadastroL(&quant_login);
realloc(L, quant_login * sizeof(login));
    }


  }
}
