#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//area de cabeçalho de função
void menuInicial();

void limpaTela(){
	system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){
	
	int linha,coluna;
	
	for(linha = 0; linha < 3; linha++){
		
		for(coluna = 0; coluna < 3; coluna++){
			
			tabuleiro[linha][coluna] = '-'; 
			
		}
		
		cout << "\n";
		
	}
	
}

void exibeTabuleiro(char tabuleiro[3][3]){
	
	int linha, coluna;
	cout << "\n";
	
	//Exibe o tabuleiro com suas linha e colunas quebrando a linha ao sair do for 
	for(linha = 0; linha < 3; linha++){
		
		for(coluna = 0; coluna < 3; coluna++){
			
			cout << tabuleiro[linha][coluna];
			
		}
		
		cout << "\n";
		
	}
	
}

//1 - X significa que X venceu, 2 - O significa que O venceu 
int confereTabuleiro(char tabuleiro[3][3]){
	
	int linha, coluna;
	
	//confere linhas
	for(linha = 0; linha < 3; linha++){
		
		if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
			
			return 1;
			
		}else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
			
			return 2;
		
		}		
			
	}
	
	//confere colunas
	for(coluna = 0; coluna < 3; coluna++){
		
		if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){

			return 1;
		
		}else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
	
			return 2;
		
		}		
			
	}
	
	//Diagonal principal 
	if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
		if(tabuleiro[0][0] == 'X'){
			
			return 1;
			
		}else{
		
			return 2;
			
		}
		
	}
	
	//Diagonal secundaria
	if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
		if(tabuleiro[0][0] == 'X'){
		
			return 1;
			
		}else{
			
			return 2;
			
		}
		
	}
	
	return 0;
}

void exibeInstrucoes(){
	
	cout << "\nMapa de posicaoes";
	cout << "\n 7 | 8 | 9";
	cout << "\n 4 | 5 | 6";
	cout << "\n 1 | 2 | 3";
	
}

void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int potucaoJogadorUm, int potucaoJogadorDois){
	
	///Variaveis Gerais
	string  nomeDoJogadorAtual;								//nomes dos jogadores 
	char tabuleiro[3][3];																		//Tabuleiro
	int linha, coluna;																			//Auxiliares para tabuleiro 
	int linhaJogada, colunaJogada, posicaojogada;																//pposicao em que o jogador posiciona sua marca
	int estadoDeJogo = 1;																		// 0 = sem jogo, 1 = em jogo
	int turnoDoJogador = 1;																		// 1 = x , 2 - O
	int rodada = 0;																				//quantas vezes o jogador já jogou
	int opcao;																					//opção de reinicio
	bool posicionouJogada = false;																//Verifica se o jogador colocou um marcador no tabuleiro 
	
	
	//Coloca os '-' no tabuleiro para indicar o vazio 
	iniciaTabuleiro(tabuleiro);
	
	
	while(rodada < 9 && estadoDeJogo == 1){
	
	limpaTela();
	
	cout << "\nRodada:" << rodada << "\n";
	cout << "\nPontuacao:" << nomeDoJogadorUm << " " << potucaoJogadorUm << " x " << potucaoJogadorDois << " " << nomeDoJogadorDois << "\n";
	
	//exibe o tabuleiro 
	exibeTabuleiro(tabuleiro);
	
	exibeInstrucoes();
	
	
	//Atualiza o nome do jogador atual
	if(turnoDoJogador == 1 ){
		
		nomeDoJogadorAtual = nomeDoJogadorUm;
		
	}else{
		
		nomeDoJogadorAtual = nomeDoJogadorDois;
		
	}
	
	posicionouJogada = false;
	
	//matriz de posições possiveis 
	int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};
	
	while(posicionouJogada == false){
		
		cout << "\n" << nomeDoJogadorAtual << "\nDigite uma posicao conforme o mapa acima:";
		cin >> posicaojogada;
		
		//passa a linha de coluna de acordo com a matriz de posicoes exibida no mapa
		linhaJogada = posicoes[posicaojogada - 1][0];
		colunaJogada = posicoes[posicaojogada - 1][1];
	
		//verifica se a posição é vazia
		if(tabuleiro[linhaJogada][colunaJogada] == '-'){
			
			posicionouJogada = true;
		
			//Verifica de quem é a ve para posicionar o marcador 
			if(turnoDoJogador == 1){
		
				tabuleiro[linhaJogada][colunaJogada] = 'X';
		
				turnoDoJogador = 2;
		
			}else{
		
				tabuleiro[linhaJogada][colunaJogada] = 'O';
		
				turnoDoJogador = 1;
		
			}
		
		}
		
		
	}
	
	

	
	//confere se o jogo acabou
	if(confereTabuleiro(tabuleiro) == 1){
		cout << "O Jogador X venceu";
		potucaoJogadorUm++;
		estadoDeJogo = 0;
	}else if(confereTabuleiro(tabuleiro) == 2){
		cout << "O Jogador O venceu";
		potucaoJogadorDois++;
		estadoDeJogo = 0;
	}
		
	//aumenta uma rodada
	rodada++;
		
	}
	exibeTabuleiro(tabuleiro);
	cout << "\nFim de Jogo";
	cout << "\nO que deseja fazer?";
	cout << "\n1 - Continuar Jogando";
	cout << "\n2 - Menu inicial";
	cout << "\n2 - Sair";
	cin >> opcao;
	if(opcao == 1){
		jogo(nomeDoJogadorUm,nomeDoJogadorDois,potucaoJogadorUm,potucaoJogadorDois);
	}else if(opcao == 2){
		menuInicial();
	}
		
}
	
	
void menuInicial(){
	
	//opão escolhida pelo usuario
	int opcao = 0;
	
	//nomedos jogadores
	string nomeDoJogadorUm,nomeDoJogadorDois;
	
	//Enqanto o jogador não diitar umaopção valida mostrra o menu novamente 
	while(opcao < 1 || opcao > 3 ){
		
		limpaTela();
		
		cout << "Bem vindo ao jogo";
		cout << "\n1 - Jogar";
		cout << "\n2 - Sobre";
		cout << "\n3 - Sair";
		cout << "\nEScolha uma opcao e tecle ENTER: ";
		
		//Faz a leitura da opção
		cin >> opcao;
		
		
		//Faz algo de acordo com a opção escolhida
		switch(opcao){
		
			case 1:
				//inicia o jogo
				//cout << "Jogo iniciado";
				cout << "Digite o nome do Jogador 1:";
				cin >> nomeDoJogadorUm;
				cout << "Digite o nome do Jogador 2:";
				cin >> nomeDoJogadorDois;
				
				
				jogo(nomeDoJogadorUm,nomeDoJogadorDois,0,0);
				break;
			
			case 2:
			
				//informação do jogo
				cout << "Informacoes do Jogo";
				break;
			
			case 3:
			
			//Sai do jogo
			cout << "Sair do Jogo";
				break;
		}
		
	}
	
}

int main(){
	
	menuInicial();
		
	return 0;
}
