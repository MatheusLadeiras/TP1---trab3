#include <stdio.h>
#include <clocale>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

const int max_tamanho = 101;

void embaralha (char arr[], int size) {
	srand(time(0)); 
	
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    
}

int verifica_palavra (char arr[], int size) {
	int i = 0;
	if (size < 5 || size > 50) {
		return 0;
	} else {
		do {
			if(!isalpha(arr[i])) {
				return 0; 
			}
			i++;
		} while(arr[i] != '\0');
	}	
	return 1;//correto
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char palavra[max_tamanho];
    
    do {
    	int i = 0;
    	int tamanho = 0;
    	
    	memset(palavra,0,strlen(palavra));
    	
	    printf("Digite a palavra a ser embaralhada: ");
	    gets(palavra);
	    
	    if(palavra[0] != '\0') {
		    while(palavra[i] != '\0') {
		    	i++;
		    }
		    tamanho = i;
		    
			int m = verifica_palavra(palavra, tamanho);
	    	//printf("O verifica_palavra retornou %i\n", m);
	    	
	    	if (m == 1) {
	    		printf("A palavra %s se tornou", palavra);
			    embaralha(palavra, tamanho);
			    printf(" %s. \n", palavra);	
			} else if (m == 0) {
				printf("Não é uma palavra. \n");
			}	    
		} else {
			printf("Fechando programa");
		}
		
	} while (palavra[0] != '\0');

    return 0;
}


