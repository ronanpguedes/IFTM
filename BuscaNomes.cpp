#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMES 1000

/* Função que realiza a busca binária para encontrar o índice do primeiro nome que começa com o prefixo */
int encontrar_nome(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
    int esquerda = 0, direita = n - 1, meio;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        /*STRNCMP é usada para comparar duas strings
        de caracteres e determinar se elas são
         iguais ou diferentes até
         um certo número de caracteres.*/
        if (strncmp(nomes[meio], prefixo, strlen(prefixo)) >= 0) {
                /*strlen é usada para obter o comprimento de uma string,
                ou seja, o número de caracteres
                que ela contém, excluindo o
                caractere nulo de terminação ('\0').*/
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return esquerda;
}

/* Função que retorna todos os nomes que começam com o prefixo */
void buscar_nomes(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
    int indice = encontrar_nome(nomes, n, prefixo);
    /*strncmp é uma função da biblioteca padrão da linguagem C que compara os primeiros n caracteres de duas strings. 
	Ela é usada para comparar duas strings de forma segura, evitando acessar memória não alocada ou ler além dos limites das strings.*/
    for (int i = indice; i < n && strncmp(nomes[i], prefixo, strlen(prefixo)) == 0; i++) {
    	/*strlen é uma função da linguagem de programação C que retorna o comprimento de uma string, ou seja, 
		o número de caracteres que ela contém(excluindo o caractere nulo '\0' que marca o final da string).*/
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
    /*O tipo FILE é usado para declarar variáveis que representam arquivos
     e são usadas em conjunto com funções de entrada/saída de arquivos,
      como fopen, fclose, fread, fwrite, fscanf, fprintf e outras.*/
    FILE *arquivo = fopen("nomes.txt", "r");//fopen Esta é a função de abertura de arquivos
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    /* Lê os nomes do arquivo e os armazena na matriz "nomes" */
    char linha[30];
    //fgets, usada para ler uma linha de texto de um arquivo ou da entrada padrão (teclado)
    while (fgets(linha, 30, arquivo) != EOF) { //EOF null
        linha[strcspn(linha, "\n")] = '\0';  /* strcspn é uma função da linguagem de programação
		 C que retorna o comprimento do segmento inicial de uma string que não contém nenhum dos caracteres de outra string.*/
        strlwr(linha);  // converte todos os caracteres para minúsculas
        
        strcpy(nomes[n++], linha); //copiar uma string de uma variável para outra
    }

    fclose(arquivo); //fclose é uma função da linguagem de programação C que fecha um arquivo que foi aberto com fopen.

    /* Lê o prefixo a ser buscado */
    printf("Digite o prefixo: ");
    scanf("%s", prefixo);
    strlwr(prefixo);  // converte o prefixo para minúsculas

    /* Busca os nomes que começam com o prefixo */
    buscar_nomes(nomes, n, prefixo);

    return 0;
}
