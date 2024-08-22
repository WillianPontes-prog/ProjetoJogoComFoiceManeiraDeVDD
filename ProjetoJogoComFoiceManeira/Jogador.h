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

	
	int maxTempoMachucado;
	int tempoMachucado;

	

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5, Arma* arma = NULL);
	~Jogador();

	

	void move();
	void atualiza();

	State getState() { return state; };

	void setState(State state);
	void sacarArma();

	

};

