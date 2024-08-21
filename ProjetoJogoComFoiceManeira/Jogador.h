#pragma once
#include "EntidadeColisao.h"


class Jogador : public EntidadeColisao
{
public:
	enum State {
		Normal,
		Ataque,
		Machucado
	};

private:

	sf::Texture		texturaVida;
	sf::Sprite		spriteVida;

	State state;

	
	int maxTempoMachucado;
	int tempoMachucado;

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5);
	~Jogador();

	

	void move();
	void atualiza();

	State getState() { return state; };

	void setState(State state);
};

