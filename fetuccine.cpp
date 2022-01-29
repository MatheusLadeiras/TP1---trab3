#include <stdio.h>
#include <clocale>

void imprime_serie (int array[], int size) {
	printf("A série invertida com %i valores é:", size);
	for (int i = 0; i < size; i++) {
		printf(" %i", array[i]);
	}
	printf("\n"); 
}

void inverte_serie (int arr[], int size) {
	int j = size - 1;
	int i = 0;
	while (i < j) {
		int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
	}
}

void calcula_serie (int array[], int size) {
	int sinal = 0;
	for(int i = 3; i <= size; i++) {
		if(sinal == 0) {
			array[i] = array[i-3] + array[i-2] + array[i-1];
			sinal = 1;
		} else {
			array[i] = array[i-3] - array[i-2] - array[i-1];
			sinal = 0;
		}
	}
}

void le_termos_iniciais (int array[]) {
	for (int i = 0; i < 3; i++) {
	    do {
			printf("Qual o %iº valor da sequência? ", i + 1);
			scanf("%i", &array[i]); 
			if (array[i] <= 0) {  
				printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
			}
		} while (array[i] <= 0);
	}
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tamanho;
    
    do {
		printf("Qual o tamanho da sequência? ");
		scanf("%i", &tamanho); 
		if (tamanho <= 4) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (tamanho <= 4);
	
	int sequencia [tamanho + 1];
		
	le_termos_iniciais(sequencia);
	
	printf("Os valores iniciais são:");
	for (int i = 0; i < 3; i++) {
		printf(" %i", sequencia[i]);
		if (i != 2) {
			printf(",");
		}
	}
	printf("\n");
	
	calcula_serie(sequencia, tamanho);
	
/*	printf("A série não invertida é:");
	for (int i = 0; i < tamanho; i++) {
		printf(" %i", sequencia[i]);
		if (i != tamanho - 1) {
			printf(",");
		}
	}
	printf("\n"); */
	
	inverte_serie(sequencia, tamanho);
	
	/* printf("A série invertida é:");
	for (int i = 0; i < tamanho; i++) {
		printf(" %i", sequencia[i]);
		if (i != tamanho - 1) {
			printf(",");
		}
	}
	printf("\n"); */
	
	imprime_serie(sequencia, tamanho);

    return 0;
}
