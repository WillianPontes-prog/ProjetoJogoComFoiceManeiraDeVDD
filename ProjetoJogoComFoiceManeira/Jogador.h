#pragma once
#include "EntidadeColisao.h"



class Jogador : public EntidadeColisao
{
public:
	enum State {
		Normal,
		Recarregando,
		Machucado
	};

private:
	

	sf::Texture		texturaVida;
	sf::Sprite		spriteVida;

	State state;

	


	sf::Vector2f posicaoInicial;
	
	bool jogador2;

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5, Arma* arma = NULL, bool jogador2 = false);
	~Jogador();

	void move();
	void atualiza();

	State getState() { return state; };

	void setState(State state);
	void sacarArma();

	sf::Vector2f getPosicaoInicial() { return posicaoInicial; };

	bool getJogador2() { return jogador2; };
};

