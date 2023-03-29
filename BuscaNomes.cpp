#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMES 1000

/* Fun��o que realiza a busca bin�ria para encontrar o �ndice do primeiro nome que come�a com o prefixo */
int encontrar_nome(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
    int esquerda = 0, direita = n - 1, meio;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        /*STRNCMP � usada para comparar duas strings
        de caracteres e determinar se elas s�o
         iguais ou diferentes at�
         um certo n�mero de caracteres.*/
        if (strncmp(nomes[meio], prefixo, strlen(prefixo)) >= 0) {
                /*strlen � usada para obter o comprimento de uma string,
                ou seja, o n�mero de caracteres
                que ela cont�m, excluindo o
                caractere nulo de termina��o ('\0').*/
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return esquerda;
}

/* Fun��o que retorna todos os nomes que come�am com o prefixo */
void buscar_nomes(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
    int indice = encontrar_nome(nomes, n, prefixo);
    /*strncmp � uma fun��o da biblioteca padr�o da linguagem C que compara os primeiros n caracteres de duas strings. 
	Ela � usada para comparar duas strings de forma segura, evitando acessar mem�ria n�o alocada ou ler al�m dos limites das strings.*/
    for (int i = indice; i < n && strncmp(nomes[i], prefixo, strlen(prefixo)) == 0; i++) {
    	/*strlen � uma fun��o da linguagem de programa��o C que retorna o comprimento de uma string, ou seja, 
		o n�mero de caracteres que ela cont�m(excluindo o caractere nulo '\0' que marca o final da string).*/
        printf("%s\n", nomes[i]);
    }
   /* void converterMinusculo(char nomes[]){
    	for (int i; )
	}*/
}

int main() {
    char nomes[MAX_NOMES][30];//matroz de nomes 
    char prefixo[30]; // vetor de prefixo
    int n = 0;
    /*O tipo FILE � usado para declarar vari�veis que representam arquivos
     e s�o usadas em conjunto com fun��es de entrada/sa�da de arquivos,
      como fopen, fclose, fread, fwrite, fscanf, fprintf e outras.*/
    FILE *arquivo = fopen("nomes.txt", "r");//fopen Esta � a fun��o de abertura de arquivos
    if (arquivo == NULL) {
        printf("N�o foi poss�vel abrir o arquivo.\n");
        return 1;
    }

    /* L� os nomes do arquivo e os armazena na matriz "nomes" */
    char linha[30];
    //fgets, usada para ler uma linha de texto de um arquivo ou da entrada padr�o (teclado)
    while (fgets(linha, 30, arquivo) != EOF) { //EOF null
        linha[strcspn(linha, "\n")] = '\0';  /* strcspn � uma fun��o da linguagem de programa��o
		 C que retorna o comprimento do segmento inicial de uma string que n�o cont�m nenhum dos caracteres de outra string.*/
        strlwr(linha);  // converte todos os caracteres para min�sculas
        
        strcpy(nomes[n++], linha); //copiar uma string de uma vari�vel para outra
    }

    fclose(arquivo); //fclose � uma fun��o da linguagem de programa��o C que fecha um arquivo que foi aberto com fopen.

    /* L� o prefixo a ser buscado */
    printf("Digite o prefixo: ");
    scanf("%s", prefixo);
    strlwr(prefixo);  // converte o prefixo para min�sculas

    /* Busca os nomes que come�am com o prefixo */
    buscar_nomes(nomes, n, prefixo);

    return 0;
}
