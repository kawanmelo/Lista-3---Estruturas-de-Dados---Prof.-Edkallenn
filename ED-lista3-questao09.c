#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** Função : Classifica os elementos de um vetor usando o algoritmo BubbleSort e realiza a CONTAGEM do
números de if's realizados e a quantidade de trocas realizadas.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 18.05.2024
** Observações: Utilizei a função "clear_keyboard_buffer()" para limpar o buffer
*do teclado e assim conseguir utilizar corretamente a função "getchar()".
*/

void clear_keyboard_buffer(void) {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  return;
}

void BubbleSort(int *vetor, int tam){
  int ifsCount = 0;
  int changesCount = 0;
  for(int i=0; i<tam; i++){
    int verificaPassagemSemTroca=0;
    for(int j=0; j<tam-i-1; j++){
      ifsCount++;
      if(vetor[j] > vetor[j+1]){
        int temp = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = temp;
        verificaPassagemSemTroca++;
        changesCount++;
      }
    }
    if(verificaPassagemSemTroca==0){
      break;
    }
  }
  printf("Número de If's realizados: %d\n", ifsCount);
  printf("Número de Trocas realizadas: %d\n", changesCount);
}

int main(void) {
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("ORDENE O VETOR (BubbleSort)\n");
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

  clear_keyboard_buffer();
  printf("Pressione a tecla 'enter' para ordenar o vetor...");
  getchar();
  BubbleSort(vetor, tam);

  printf("Vetor ordenado = [ ");
  for (int i = 0; i < tam; i++) {
    printf("%d, ", vetor[i]);
  }
  printf("\b\b ]\n");
  
  return 0;
}