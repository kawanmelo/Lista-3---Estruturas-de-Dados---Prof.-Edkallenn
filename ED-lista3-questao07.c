#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** Função : Classificar os elementos de um vetor em ordem crescente usando o algoritmo “quicksort”.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 13.05.2024
** Observações : Null
*/

int Order(int vetor[], int indiceInicial, int indiceFinal) {
  int m = vetor[indiceInicial + (indiceFinal - indiceInicial) / 2];
  int i = indiceInicial;
  int j = indiceFinal;

  while (i <= j) {
      while (vetor[i] < m) {
          i++;
      }
      while (vetor[j] > m) {
          j--;
      }
      if (i <= j) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        i++;
        j--;
      }
  }
  return i;
}

void QuickSort(int vetor[], int indiceInicial, int indiceFinal) {
  if (indiceInicial < indiceFinal) {
      int indicePivo = Order(vetor, indiceInicial, indiceFinal);
      QuickSort(vetor, indiceInicial, indicePivo - 1);
      QuickSort(vetor, indicePivo, indiceFinal);
  }
}

int main(void) {
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("ORDENE O VETOR (QuickSort)\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  int tam;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam);

  int *vetor = (int *)malloc(sizeof(int) * tam);
  if (vetor == NULL) {
    printf("Erro na alocação de memória.");
    exit(1);
  }

  srand((unsigned)time(NULL));
  for (int i = 0; i < tam; i++) {
    vetor[i] = rand() % 1000;
  }
  printf("Vetor com tamanho %d e elementos aleatórios criado!\n\n", tam);

  printf("Vetor antes da ordenação = [ ");
  for (int i = 0; i < tam; i++) {
    printf("%d, ", vetor[i]);
  }
  printf("\b\b ]\n");
  QuickSort(vetor, 0, tam-1);

  printf("Vetor ordenado = [ ");
  for (int i = 0; i < tam; i++) {
    printf("%d, ", vetor[i]);
  }
  printf("\b\b ]\n");
}
