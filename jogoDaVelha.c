#include <stdio.h>
#include <stdlib.h>

#define CONST 3

/** Victor Alves: dev-alves **/

int arrayVelha[CONST][CONST];
int velhando = 0;

int verificarLinha(int nJogador) {
	int velhando = 0;
	
	for(int i = 0; i <CONST; i ++) {
		for(int j = 0; j<CONST; j ++) {
			if(arrayVelha[i][j] == nJogador) {
				velhando++;
			}
		}

		if(velhando == 3) {
			return 1;
		} else {
			velhando = 0;
		}
	}

	return 0;
}

int verificarColuna(int nJogador) {
	int velhando = 0;
	//coluna
	for(int i = 0; i<CONST; i++) {
		for(int j = 0; j<CONST; j++) {
			if(arrayVelha[j][i] == nJogador) {
				velhando++;
			}
		}

		if(velhando == 3) {
			return 1;
		} else {
			velhando = 0;
		}
	}

	return 0;
}

int verificarDiagonalPrincipal(int nJogador){
	int velhando = 0;
	for(int i=0; i<CONST; i++) {
		if(arrayVelha[i][i] == nJogador) {
			velhando++;
		}
	}

	if(velhando == 3) {
		return 1;
	}
	return 0;
}

int verificarDiagonalSecundaria(int nJogador) {
	int j = 0, velhando = 0;
	for(int i=CONST-1; i>=0; i--, j++) {
		if(arrayVelha[i][j] == nJogador) {
			velhando++;
		}
	}

	if(velhando == 3) {
		return 1;
	}

	return 0;
}


int inserir(int op, int nJogador) {
int error = 0;
	if (op == 1) {
		if (arrayVelha[0][0] == 0) 
			arrayVelha[0][0] = nJogador;
		else
			error++;
	} else if (op == 2) {
		if(arrayVelha[0][1] == 0)
			arrayVelha[0][1] = nJogador;
		else
			error++;
	} else if (op == 3) {
		if (arrayVelha[0][2] == 0)
			arrayVelha[0][2] = nJogador;
		else
			error++;
	} else if (op == 4) {
		if (arrayVelha[1][0] == 0)
			arrayVelha[1][0] = nJogador;
		else
			error++;
	} else if (op == 5) {
		if (arrayVelha[1][1] == 0)
			arrayVelha[1][1] = nJogador;
		else
			error++;
	} else if (op == 6) {
		if (arrayVelha[1][2] == 0)
			arrayVelha[1][2] = nJogador;
		else
			error++;
	} else if (op == 7) {
		if (arrayVelha[2][0] == 0)
			arrayVelha[2][0] = nJogador;
		else
			error++;
	} else if (op == 8) {
		if (arrayVelha[2][1] == 0)
			arrayVelha[2][1] = nJogador;
		else
			error++;
	} else if (op == 9) {
		if (arrayVelha[2][2] == 0)
			arrayVelha[2][2] = nJogador;
		else
			error++;
	}

	if (error>0){
		return 0;
	} 

	return 1;
}

int jogar(int op, int nJogador) {

	if (verificarLinha(nJogador) || verificarColuna(nJogador) || verificarDiagonalSecundaria(nJogador) || verificarDiagonalPrincipal(nJogador) == 1) {
		for(int i = 0; i <CONST; i ++) {
			printf("[");
			for(int j = 0; j<CONST; j ++) {
				printf(" %d ", arrayVelha[i][j]);
			}
			printf("]");
			printf("\n");
		}

		printf("Jogador[%d] foi o vencedor! Parabéns!\n", nJogador);
		return 1;
	} else {
		velhando++;
		if(velhando  == 9) {
			printf("Velhouuu!!\n");
			return 1;
		}
	}

	return 0;

}


int main () {

	int op = 0, velha = 0, nJogador = 1;

	while (velha != 1){
		printf("Jogo da Velha\n\n");
		for(int i = 0; i <CONST; i ++) {
			printf("[");
			for(int j = 0; j<CONST; j ++) {
				printf(" %d ", arrayVelha[i][j]);
			}
			printf("]");
			printf("\n");
		}

		int result = 0;
		
		do{
			printf("\nJogador[%d]: ", nJogador);
			scanf("%d", &op);
			result = inserir(op, nJogador);
			if(result == 0 ||  (op <= 0 || op > 9)) {
				printf("Por favor, informe uma outra posicao\n");
			}
		}while(result != 1 || (op <= 0 || op > 9) );
		
		velha = jogar(op, nJogador);
		
		if (nJogador==2) 
			nJogador = 0;
		nJogador++;
	}

}
