#include <stdio.h>
#include <clocale>
#include <stdlib.h>
#include <math.h>

struct Coordenada {   
	float cord_x;  
	float cord_y;  
};  

void calcula_circunferencia(float menor_raio, Coordenada centro) {
	printf("Centro:(%.4f, %.4f) \n", centro.cord_x, centro.cord_y);
	printf("Raio: %.4f", menor_raio);
}

float distancia (Coordenada &ponto_base, Coordenada &ponto_secund) {
	float distancia = sqrt(pow((ponto_secund.cord_x - ponto_base.cord_x), 2)+ pow((ponto_secund.cord_y - ponto_base.cord_y), 2)); //checado, está funcional
	return distancia;
}

void le_pontos(Coordenada &func, int quantidade, int x) {
	printf("Coloque as coordenadas X e Y do %iº elemento: \n", x + 1);
	printf("X: ");
	scanf("%f", &func.cord_x);
	printf("Y: ");
	scanf("%f", &func.cord_y);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int quantidade;
    
    do {
		printf("Quantos pontos tem a circunferência? ");
		scanf("%i", &quantidade); 
		if (quantidade < 4) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (quantidade < 4);
	
	Coordenada pontos[quantidade];
	
	for(int i = 0; i < quantidade; i++){
		le_pontos(pontos[i], quantidade, i);
	}
	
	float raios [quantidade+1];
	float maior_dist = 0;
	
	for(int a = 0; a < quantidade; a++) {	
		for(int b = 0; b < quantidade; b++) {
			float dist = distancia(pontos[a], pontos[b]);
				//printf("%f \n", dist);
			if (dist > maior_dist) {
				maior_dist = dist;  
				//printf("maior_dist: %f \n", maior_dist);
			}	
		}
		raios[a] = maior_dist;
		maior_dist = 0;
	}
	
	printf("Os raios tendo um dos pontos como centro são:");
	for (int i = 0; i < quantidade; i++) {
		printf(" %.4f", raios[i]);
	}
	printf("\n"); 
	
	float menor_raio = raios[0];
	int cord_central = 0;
	for(int o = 1; o < quantidade; o++) {
		if (raios[o] < menor_raio) { 
				menor_raio = raios[o];
				cord_central = o; 
			}
	}
	
	calcula_circunferencia(menor_raio,pontos[cord_central]);

    return 0;
}
