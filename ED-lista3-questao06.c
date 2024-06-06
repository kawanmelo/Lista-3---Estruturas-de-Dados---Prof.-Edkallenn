#include <stdio.h>

/*
** Função : Criar um algoritmo e aplicar o método de Newton-Raphson em uma função para calcular a raiz quadrada de um número n com aproximação de 0.0001
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 05.06.2024
** Observações : Null
*/


// f(x) = x^2 - n; f'(x) = 2x
double CalculaRaiz(double n){
  double x0 = n/2;
  double xn = x0 - ((x0 * x0 - n) / (2 * x0));
  double diferenca = xn - x0;
  double pontoDeParada = 0.0001;
  if(diferenca < 0){
    diferenca = diferenca * -1;
  }
  while(diferenca > pontoDeParada){
    double xn1 = xn - ((xn * xn - n) / (2 * xn));
    diferenca = xn1 - xn;
    if(diferenca < 0){
      diferenca = diferenca * -1;
    }
    xn = xn1;
  }
  return xn;
}

int main(void) {
  double n;
  double raiz = 0;
  printf("---- Método de Newton-Raphson -----\n\n");
  printf("Digite um número: ");
  scanf("%lf", &n);
  raiz = CalculaRaiz(n);
  printf("A raiz quadrada de %lf é ≅ %lf", n, raiz);
  return 0;
}