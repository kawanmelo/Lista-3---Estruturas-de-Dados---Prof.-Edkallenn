#include <stdio.h>
#include <stdlib.h>

/*
** Função : Demonstrar a veracidade da afirmação: "Todo inteiro par maior que 2 é a soma de dois" testando entre 700 e 1100
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 12.05.2024
** Observações : Null
*/

int* CacthPrimeNumbers(int ini, int end){
  int *numerosPrimos = malloc(sizeof(int) * (end-ini));
  int aux=0;
  for(int i=ini; i<=end; i++){
    int count=0;
    for(int j = i-1; j>1; j--){
      if(i%j == 0){
        count++;
      }
    }
    if(count==0){
      numerosPrimos[aux] = i;
      aux++;
    }
  }
  return numerosPrimos;
}

int AnalyzeGoldbachConjecture(int num){
  if(num%2 != 0){
    return 1;
  }
  int *vetorPrimos = CacthPrimeNumbers(2, num);
  for(int i=0; vetorPrimos[i]!=0; i++){
    for(int j=0; vetorPrimos[j]!=0; j++){
      if(vetorPrimos[i] + vetorPrimos[j] == num){
        printf("%d = %d + %d\n", num, vetorPrimos[i], vetorPrimos[j]);
        return 0;
      }
    }
  }
}

int main(void) {
  int num;
  printf("Verificando Conjectura de Goldbach entre 700 e 1100\n\n");

  for(int i=700; i<=1100; i++){
    AnalyzeGoldbachConjecture(i);
  }
  
  return 0;
}