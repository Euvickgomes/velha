#include <stdio.h>

#define TAM 3
void mostrarMatriz(char matriz[TAM][TAM]){
	int i, j;

	printf("\n");
	printf("     ");
	for(i = 0; i < TAM; i++){
	    printf("  %d  ", i);
	}
	
	printf("\n");
	
	for(i = 0; i < TAM; i++){
	     printf("  %d  ", i);
		for(j = 0; j < TAM; j++){
			printf(" %c ", matriz[i][j]);
			if(j < (TAM - 1)){
				printf(" | ");
			}
		}
		if(i < (TAM - 1)){
			printf("\n     ---------------\n");
		}
	}
	printf("\n");
}

void jogar(char matriz[TAM][TAM]){
	int jogadas = 0, jogador = 0, i, j, erro = 2;
	
	while(jogadas < 9){
		
		if(jogador % 2 == 0){
		    printf("\nJogada %d", jogadas+1);
			printf("\nX, digite sua jogada Linha, Coluna ex: 0 0\n");
			scanf("%d %d", &i, &j);
			
			if(matriz[i][j] == ' '){
				matriz[i][j] = 'X';
				mostrarMatriz(matriz);
				if(jogadas >= 3){
				    if(verificar(matriz) == 1){
					printf("\nJogador X ganhou!!");
					jogadas = 9;
				}
			}
				jogadas++;
			} else{
				erro++;
				jogadas = 9;
			}
		} else{
		    printf("\nJogada %d", jogadas+1);
			printf("\nO, digite sua jogada Linha, Coluna ex: 0 0\n");
			scanf("%d %d", &i, &j);
			
			if(matriz[i][j] == ' '){
				matriz[i][j] = 'O';
				mostrarMatriz(matriz);
				if(jogadas >= 5){
				    if(verificar(matriz) == 1){
					printf("\nJogador O ganhou!!");
					jogadas = 9;
				}
			}
				jogadas++;
			} else{
				erro++;
				jogadas = 9;
			}
		}
		
		if (jogadas == 8){
		    printf("Ultima jogada");
		}
		
		jogador++;
		
	}
	if (jogadas == 9 && erro == 3){
	    printf("\nJogada invalida!!");
	} else if (jogadas == 9 && erro != 3){
	    printf("\n        VELHAAA");
	}
	
}

int verificar(char matriz[TAM][TAM]){
	
	if(matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] && matriz[0][0] != ' '){
		return 1;
	} else if(matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] && matriz[1][0] != ' '){
		return 1;
	} else if(matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] && matriz[2][0] != ' '){
		return 1;
	}
	
	if(matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] && matriz[0][0] != ' '){
		return 1;
	}else if(matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] && matriz[0][1] != ' '){
		return 1;
	} else if(matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2]  && matriz[0][2] != ' '){
		return 1;
	}
	
	if(matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' '){
		return 1;
	} else if(matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' '){
		return 1;
	}
	
	return 0;
}

main(){
	char matriz[TAM][TAM]= {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
	
	mostrarMatriz(matriz);
	jogar(matriz);
}
