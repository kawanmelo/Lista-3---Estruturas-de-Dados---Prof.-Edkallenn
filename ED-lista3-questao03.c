#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função : Criar um novo tipo de dado, definir um vetor do novo tipo e
*implementar rotinas para ler, escrever e excluir registros deste tipo
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 12.05.2024
** Observações :  Defini o tamanho do campo "sigla" como [4](a. Sigla: string com até 3 caracteres) para lidar melhor com a impressão no console
*/

typedef struct aeroporto Aeroporto;

struct aeroporto {
  char sigla[4];
  char cidade[50];
  char pais[30];
  double taxa;
  int capacidade;
};

// Função para criar um vetor de ponteiros para dados do tipo Aeroporto
Aeroporto **CriaVetorAeroportos(int tam) {
  Aeroporto **vetorAeroporto = malloc(sizeof(Aeroporto *) * tam);
  if (vetorAeroporto == NULL) {
    printf("Erro na alocação de mémoria.");
    return NULL;
  }
  return vetorAeroporto;
}

// Função para definir os campos da estrutura e criar um ponteiro para o dado
// criado
Aeroporto *CriaAeroporto(char sigla[], char cidade[], char pais[], double taxa,
                         int capacidade) {
  Aeroporto *aeroporto = malloc(sizeof(Aeroporto));
  if (aeroporto == NULL) {
    printf("Erro na alocação de memória!.");
    return NULL;
  }
  strcpy(aeroporto->sigla, sigla);
  strcpy(aeroporto->cidade, cidade);
  strcpy(aeroporto->pais, pais);
  aeroporto->taxa = taxa;
  aeroporto->capacidade = capacidade;
  return aeroporto;
}

// Função para inserir um elemento no vetor
void InsereAeroporto(Aeroporto **vetorAeroportos, Aeroporto *aeroportoNovo) {
  int i = 0;
  int j = 0;
  while (i == 0) {
    Aeroporto *marcadorAeroporto = vetorAeroportos[j];
    if (marcadorAeroporto == NULL) {
      vetorAeroportos[j] = aeroportoNovo;
      i++;
    }
    j++;
  }
}

// Função para remover um elemento do vetor
void RemoveAeroporto(Aeroporto **vetorAeroportos, Aeroporto *aeroporto) {
  int j;
  for (int i = 0; vetorAeroportos[i] != NULL; i++) {
    if (strcmp(aeroporto->sigla, vetorAeroportos[i]->sigla) == 0) {
      int aux = i;
      for (j = i + 1; vetorAeroportos[j] != NULL; j++) {
        vetorAeroportos[aux] = vetorAeroportos[j];
      }
      vetorAeroportos[j - 1] = NULL;
    }
  }
}

// Função para verificar se um elemento está contido no vetor
Aeroporto *BuscaAeroporto(Aeroporto **vetorAeroportos, Aeroporto *aeroporto) {
  int i = 0;
  while (vetorAeroportos[i] != NULL) {
    if (strcmp(aeroporto->sigla, vetorAeroportos[i]->sigla) == 0) {
      printf("ELemento encontrado\n");
      return vetorAeroportos[i];
    }
    i++;
  }
  printf("Elemento não encontrado\n");
  return NULL;
}

// Função para imprimir todos os elementos do vetor e seus campos
void MostraAeroportos(Aeroporto **vetorAeroportos) {
  printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
  for (int i = 0; vetorAeroportos[i] != NULL; i++) {
    printf("Aeroporto: %s\n", vetorAeroportos[i]->sigla);
    printf("Cidade: %s\n", vetorAeroportos[i]->cidade);
    printf("País: %s\n", vetorAeroportos[i]->pais);
    printf("Taxa: %.4f\n", vetorAeroportos[i]->taxa);
    printf("Capacidade: %d\n\n", vetorAeroportos[i]->capacidade);
  }
  printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
}

int main(void) {
  Aeroporto **vetor = CriaVetorAeroportos(6);
  Aeroporto *aeroporto1 = CriaAeroporto("ALE", "BrothersCity", "Brasil", 1.47, 71427);
  Aeroporto *aeroporto2 = CriaAeroporto("IJA", "LoveCity", "Brasil", 2.54, 
  99999);
  Aeroporto *aeroporto3 = CriaAeroporto("JUR", "DualCity", "Brasil", 7.12, 85000);
  Aeroporto *aeroporto4 = CriaAeroporto("MIC", "SisterCity", "Brasil", 7.58, 5489);
  Aeroporto *aeroporto5 = CriaAeroporto("VIC", "BrothersCity", "Brasil", 1.87, 71427);
  Aeroporto *aeroporto7 = CriaAeroporto("KAW", "LostCity", "Brasil", 3.14, 14);

  InsereAeroporto(vetor, aeroporto1);
  InsereAeroporto(vetor, aeroporto2);
  InsereAeroporto(vetor, aeroporto3);
  InsereAeroporto(vetor, aeroporto4);
  InsereAeroporto(vetor, aeroporto5);
  InsereAeroporto(vetor, aeroporto7);
  MostraAeroportos(vetor);
  RemoveAeroporto(vetor, aeroporto7);
  MostraAeroportos(vetor);
  
  return 0;
}
