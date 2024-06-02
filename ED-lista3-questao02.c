#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
** Função : Criar um novo tipo de dado, definir um vetor do novo tipo e implementar rotinas para ler, escrever e excluir registros deste tipo
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 11.05.2024
** Observações: Null
*/

// Definição da estruruta Empregado
typedef struct empregado Empregado;

struct empregado {
  char nome[50];
  char dataDeNascimento[11];
  char rg[11];
  char dataDeAdmissao[11];
  double salario;
};

// Função para criar um vetor de ponteiros para dados do tipo Empregado
Empregado **CriaVetorEmpregados(int tam) {
  Empregado **vetorEmpregados = malloc(sizeof(Empregado *) * tam);
  if (vetorEmpregados == NULL) {
    printf("Erro na alocação de mémoria.");
    return NULL;
  }
  return vetorEmpregados;
}

// Função para definir os campos da estrutura e criar um ponteiro para o dado
// criado
Empregado *CriaEmpregado(char nome[], char nascimento[], char rg[],
                         char admissao[], double salario) {
  Empregado *empregado = malloc(sizeof(Empregado));
  if (empregado == NULL) {
    printf("Erro na alocação de memória!.");
    return NULL;
  }
  strcpy(empregado->nome, nome);
  strcpy(empregado->dataDeNascimento, nascimento);
  strcpy(empregado->rg, rg);
  strcpy(empregado->dataDeAdmissao, admissao);
  empregado->salario = salario;
  return empregado;
}

// Função para inserir um elemento no vetor
void InsereEmpregado(Empregado **vetorEmpregados, Empregado *empregadoNovo) {
  int i = 0;
  int j = 0;
  while (i == 0) {
    Empregado *marcadorEmpregado = vetorEmpregados[j];
    if (marcadorEmpregado == NULL) {
      vetorEmpregados[j] = empregadoNovo;
      i++;
    }
    j++;
  }
}

// Função para remover um elemento do vetor
void RemoveEmpregado(Empregado **vetorEmpregados, Empregado *empregado) {
  int j;
  for (int i = 0; vetorEmpregados[i] != NULL; i++) {
    if (strcmp(empregado->rg, vetorEmpregados[i]->rg) == 0) {
      int aux = i;
      for (j = i + 1; vetorEmpregados[j] != NULL; j++) {
        vetorEmpregados[aux] = vetorEmpregados[j];
      }
      vetorEmpregados[j - 1] = NULL;
    }
  }
}

// Função para verificar se um elemento está contido no vetor 
Empregado *BuscaEmpregado(Empregado **vetorEmpregados, Empregado *empregado) {
  int i = 0;
  while (vetorEmpregados[i] != NULL) {
    if (strcmp(empregado->rg, vetorEmpregados[i]->rg) == 0) {
      printf("ELemento encontrado\n");
      return vetorEmpregados[i];
    }
    i++;
  }
  printf("Elemento não encontrado\n");
  return NULL;
}

// Função para imprimir todos os elementos do vetor e seus campos
void MostraEmpregado(Empregado **vetorEmpregados) {
  for (int i = 0; vetorEmpregados[i] != NULL; i++) {
    printf("Empregado: %s\n", vetorEmpregados[i]->nome);
    printf("Data de Nascimento: %s\n", vetorEmpregados[i]->dataDeNascimento);
    printf("RG: %s\n", vetorEmpregados[i]->rg);
    printf("Data de Admissão: %s\n", vetorEmpregados[i]->dataDeAdmissao);
    printf("Salário: %.2f\n\n", vetorEmpregados[i]->salario);
  }
}

int main(void) {
  Empregado **vetor = CriaVetorEmpregados(5);
  Empregado *empregado1 = CriaEmpregado("Joao Silva", "01.01.1980", "123456789",
                                        "01.01.2000", 2500.00);
  Empregado *empregado2 = CriaEmpregado("Maria Souza", "05.10.1975",
                                        "987654321", "15.03.1998", 2800.00);
  Empregado *empregado3 = CriaEmpregado("Pedro Santos", "10.07.1990",
                                        "456789123", "20.06.2015", 3000.00);
  InsereEmpregado(vetor, empregado1);
  InsereEmpregado(vetor, empregado2);
  InsereEmpregado(vetor, empregado3);
  MostraEmpregado(vetor);
  BuscaEmpregado(vetor, empregado2);
  RemoveEmpregado(vetor, empregado2);
  MostraEmpregado(vetor);
  BuscaEmpregado(vetor, empregado2);

  return 0;
}