#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct carro
{
  int cod;
  char marca[20];
  char modelo[20];
  int ano;
  char placa[8];
};
typedef struct carro carro;
const unsigned int TAMANHO_CADASTRO = 10;
unsigned int CARROS_CADASTRADOS = 0;
carro cadastro[10];

void limpaCadastro()
{
  for (unsigned int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    cadastro[i].cod = 0;
    memset(cadastro[i].marca, ' ', 20);
    memset(cadastro[i].modelo, ' ', 20);
    cadastro[i].ano = 0;
    memset(cadastro[i].placa, ' ', 8);
  }
}

int menu()
{
  int opcao = 0;
  while (opcao == 0)
  {
    printf("**********SISTEMA DA ORYANGE STRIFEZZE********* \n");
    printf("|----------------------------------------- |\n");
    printf("|********* MENU DE OPÇÕES *********       |\n");
    printf("|------------------------------------------|\n");
    printf("|1 - CADASTRAR VEÍCULO                    |\n");
    printf("|2 - LISTAR VEÍCULOS CADASTRADOS          |\n");
    printf("|3 - PESQUISAR VEÍCULOS                   |\n");
    printf("|4 - MOSTRA VEÍCULOS A PARTIR DE UM ANO   |\n");
    printf("|5 - SAIR                                 |\n");
    printf("|---------------------------------------- |\n");
    printf("\n\n INFORME SUA OPÇÃO: ");
    scanf("%d", &opcao);
    if (opcao > 5 || opcao < 0)
    {
      printf("opção %d inválida", opcao);
      opcao = 0;
    }
  }
  return opcao;
}

void salvarCadastro() {
  FILE *arquivo;
  arquivo = fopen ("CADASTRO.txt", "w+");
  for(int i=0; i<CARROS_CADASTRADOS; i++) {
    fprintf(arquivo, "Marca: %s \n",cadastro[i].marca);
    fprintf(arquivo, "Modelo: %s \n",cadastro[i].modelo);
    fprintf(arquivo, "Ano: %d \n",cadastro[i].ano);
    fprintf(arquivo, "Placa: %s \n",cadastro[i].placa);
  }
  fclose(arquivo);
}

void cadastrarCarro()
{
  if (CARROS_CADASTRADOS < TAMANHO_CADASTRO)
  {
    puts("Entre com a Marca: ");
    scanf("%19s", cadastro[CARROS_CADASTRADOS].marca);
    printf("Marca: %s \n", cadastro[CARROS_CADASTRADOS].marca);

    puts("Entre com o Modelo: ");
    scanf("%19s", cadastro[CARROS_CADASTRADOS].modelo);
    printf("Modelo: %s \n", cadastro[CARROS_CADASTRADOS].modelo);

    puts("Entre com a Ano: ");
    scanf("%d", &cadastro[CARROS_CADASTRADOS].ano);
    printf("Ano: %d \n", cadastro[CARROS_CADASTRADOS].ano);

    puts("Entre com a Placa: ");
    scanf("%7s", cadastro[CARROS_CADASTRADOS].placa);
    printf("Placa: %s \n", cadastro[CARROS_CADASTRADOS].placa);

    cadastro[CARROS_CADASTRADOS].cod = CARROS_CADASTRADOS + 1;
    CARROS_CADASTRADOS++;
    salvarCadastro();
    printf("Cadastro realizado com sucesso! \n");
  }
  else
  {
    printf("\n Limite de cadastro é 10!");
  }
}

void listarCarros()
{
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (cadastro[i].cod > 0)
    {
      printf("\n O ano do veículo é: %d", cadastro[i].ano);
      printf("\n A marca do veículo é: %s", cadastro[i].marca);
      printf("\n O modelo do veículo é: %s", cadastro[i].modelo);
      printf("\n A placa do veículo é: %s", cadastro[i].placa);
      printf("\n\n =================================== \n \n");
    }
  }
}

void pesquisar()
{
  printf("\n INSIRA O MODELO A SER PESQUISADO:");
  char modeloPesquisa[20];
  int modeloEncontrado = 0;
  scanf("%19s", modeloPesquisa);
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (cadastro[i].cod > 0 && strcmp(cadastro[i].modelo, modeloPesquisa) == 0)
    {
      printf("\n O ano do veículo é: %d", cadastro[i].ano);
      printf("\n A marca do veículo é: %s", cadastro[i].marca);
      printf("\n O modelo do veículo é: %s", cadastro[i].modelo);
      printf("\n A placa do veículo é: %s", cadastro[i].placa);
      printf("\n\n =================================== \n \n");
      modeloEncontrado = 1;
    };
  }
  if (modeloEncontrado == 0)
  {
    printf("\n NÃO FOI ENCONTRADO O MODELO %s \n\n", modeloPesquisa);
  }
}

void pesquisaAno()
{
  int anoPesquisa;
  int anoEncontrado = 0;
  printf("\n  INSIRA O ANO A SER PESQUISADO:");
  scanf("%d", &anoPesquisa);
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (cadastro[i].ano == anoPesquisa)
    {
      printf("\n O ano do veículo é: %d", cadastro[i].ano);
      printf("\n A marca do veículo é: %s", cadastro[i].marca);
      printf("\n O modelo do veículo é: %s", cadastro[i].modelo);
      printf("\n A placa do veículo é: %s", cadastro[i].placa);
      printf("\n\n =================================== \n \n");
      anoEncontrado = 1;
    }
  }
  if (anoEncontrado == 0)
  {
    printf("\n NÃO FOI ENCONTRADO O ANO %d \n\n", anoPesquisa);
  }
}
int main(int argc, char **argv)
{
  limpaCadastro();
  int opcao = 0;
  do
  {
    opcao = menu();
    switch (opcao)
    {
    case 1:
      cadastrarCarro();
      break;
    case 2:
      listarCarros();
      break;
    case 3:
      pesquisar();
      break;
    case 4:
      pesquisaAno();
      break;
    }
  } while (opcao != 5);
  printf("\n Obrigado por utilizar nosso programa! até breve, aperte 0 para encerrar o programa");
  return 0;
}