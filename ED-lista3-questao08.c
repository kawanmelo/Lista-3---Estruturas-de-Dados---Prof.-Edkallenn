#include <stdio.h>
#include <stdlib.h>

/*
** Função : Criar um TAD chamado Complexo para representar e realizar operações aritméticas com números complexos.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 18.05.2024
** Observações: Null
*/

typedef struct complexo Complexo;

struct complexo{
  double parteReal;
  double parteImaginaria;
  int potenciaDaParteImaginaria;
};


Complexo* CriaComplexo(double parteReal, double parteImaginaria){
  Complexo *complexo = malloc(sizeof(Complexo));
    
  complexo->parteReal = parteReal;
  complexo->parteImaginaria = parteImaginaria;
  return complexo;
}

void DestroiComplexo(Complexo *complexo){
  free(complexo);
}

void ExibeComplexo(Complexo *complexo){
  if(complexo->parteImaginaria > 0){
    printf("%.2f + %.2fi\n", complexo->parteReal, complexo->parteImaginaria);
  }else if(complexo->parteImaginaria == 0){
    printf("%.2f\n", complexo->parteReal);
  }
  else{
    printf("%.2f - %.2fi\n", complexo->parteReal, (complexo->parteImaginaria * -1));
  }
}

Complexo* SomaComplexos(Complexo *complexo1, Complexo *complexo2){
  double parteReal = complexo1->parteReal + complexo2->parteReal;
  double parteImaginaria = complexo1->parteImaginaria + complexo2->parteImaginaria;
  Complexo *novoComplexo = CriaComplexo(parteReal, parteImaginaria);
  return novoComplexo;
} 

Complexo* SubtraiComplexos(Complexo *complexo1, Complexo *complexo2){
  double parteReal = complexo1->parteReal + (complexo2->parteReal * -1);
  double parteImaginaria = complexo1->parteImaginaria + (complexo2->parteImaginaria * -1);
  Complexo *novoComplexo = CriaComplexo(parteReal, parteImaginaria);
  return novoComplexo;
}

Complexo* MultiplicaComplexos(Complexo *complexo1, Complexo *complexo2){
  double parteReal = complexo1->parteReal * complexo2->parteReal;
  double imaginario1 = complexo1->parteReal * complexo2->parteImaginaria;
  double imaginario2 = complexo1->parteImaginaria * complexo2->parteReal;
  double imaginario3 = (complexo1->parteImaginaria * complexo2->parteImaginaria) * -1;
  double parteImaginaria = imaginario1 + imaginario2;
  parteReal = parteReal + imaginario3;

  Complexo *novoComplexo = CriaComplexo(parteReal, parteImaginaria);
  return novoComplexo;
}

Complexo* DivideComplexos(Complexo *complexo1, Complexo *complexo2){
  Complexo *conjugado = CriaComplexo(complexo2->parteReal, complexo2->parteImaginaria * -1);
  Complexo *produto1 = MultiplicaComplexos(complexo1, conjugado);
  Complexo *produto2 = MultiplicaComplexos(complexo2, conjugado);
  Complexo *novoComplexo = CriaComplexo(produto1->parteReal/produto2->parteReal, produto1->parteImaginaria/produto2->parteReal);
  return novoComplexo;
}

void LeNumerosComplexos(Complexo **complexo1, Complexo **complexo2) {
  double parteReal, parteImaginaria;

  if (*complexo1 != NULL){
    DestroiComplexo(*complexo1);
  }
  if (*complexo2 != NULL){
    DestroiComplexo(*complexo2);
  }

  printf("Digite a parte real do primeiro número complexo: ");
  scanf("%lf", &parteReal);
  printf("Digite a parte imaginária do primeiro número complexo: ");
  scanf("%lf", &parteImaginaria);
  *complexo1 = CriaComplexo(parteReal, parteImaginaria);

  printf("Digite a parte real do segundo número complexo: ");
  scanf("%lf", &parteReal);
  printf("Digite a parte imaginária do segundo número complexo: ");
  scanf("%lf", &parteImaginaria);
  *complexo2 = CriaComplexo(parteReal, parteImaginaria);
}

void LimpaTela() {
    printf("Aperte enter para continuar...");
    getchar();
    system("clear"); // ou "cls" no Windows
}

int main(void) {
    int opcao;
    Complexo *complexo1 = NULL, *complexo2 = NULL, *resultado = NULL;

    LeNumerosComplexos(&complexo1, &complexo2);

    do {
        printf("\n--- Calculadora de Números Complexos ---\n");
        printf("1. Redefinir números complexos\n");
        printf("2. Exibir números complexos\n");
        printf("3. Somar números complexos\n");
        printf("4. Subtrair números complexos\n");
        printf("5. Multiplicar números complexos\n");
        printf("6. Dividir números complexos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                LeNumerosComplexos(&complexo1, &complexo2);
                getchar();
                LimpaTela();
                break;

            case 2:
                printf("Primeiro número complexo: ");
                ExibeComplexo(complexo1);
                printf("Segundo número complexo: ");
                ExibeComplexo(complexo2);
                LimpaTela();
                break;

            case 3:
                resultado = SomaComplexos(complexo1, complexo2);
                printf("Resultado da soma: ");
                ExibeComplexo(resultado);
                DestroiComplexo(resultado);
                LimpaTela();
                break;

            case 4:
                resultado = SubtraiComplexos(complexo1, complexo2);
                printf("Resultado da subtração: ");
                ExibeComplexo(resultado);
                DestroiComplexo(resultado);
                LimpaTela();
                break;

            case 5:
                resultado = MultiplicaComplexos(complexo1, complexo2);
                printf("Resultado da multiplicação: ");
                ExibeComplexo(resultado);
                DestroiComplexo(resultado);
                LimpaTela();
                break;

            case 6:
                resultado = DivideComplexos(complexo1, complexo2);
                printf("Resultado da divisão: ");
                ExibeComplexo(resultado);
                DestroiComplexo(resultado);
                LimpaTela();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                LimpaTela();
                break;
        }
    } while (opcao != 0);

    if (complexo1 != NULL) DestroiComplexo(complexo1);
    if (complexo2 != NULL) DestroiComplexo(complexo2);

    return 0;
}