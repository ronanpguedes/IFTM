#include <stdio.h>

bool  buscaBinaria(int vetor[],int tamanho, int posicao){

int inicio = 0, finalArray = tamanho -1;

			//calcular o incio
	while (inicio <= finalArray){
		int meio = (inicio + finalArray) / 2;
		if(posicao == vetor[meio]){
			return true; /*posicao mostra a escolha que foi feita */
			//calcular o meio
		}else if(posicao < vetor[meio]){
			 finalArray = meio -1;

			 // calcular o finalArray
		}else if (posicao > vetor[meio]){
			inicio = meio +1;
		}
	}
	return false; /*returno posicaçao caso nao encontrada*/
}

int main (){

	int vetor[] = { 1, 4, 5, 8, 9, 15, 22, 38, 40, 45 };

	printf("%d \n", buscaBinaria(vetor, 10 /*Tamanho*/, 22 /*Posicao*/));



	return 0;
}

