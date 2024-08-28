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
	bool voador;

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5, Arma* arma = NULL, bool jogador2 = false, bool voar = false);
	~Jogador();

	void move();
	void atualiza();

	State getState() { return state; };

	void setState(State state);
	void sacarArma();
	json toJson() {
		int T = Tipo::_jogador;

		if (jogador2)
			T = Tipo::_jogador2;
		return json{ { "class", T}, {"posX", getBody().getPosition().x},  {"posY", getBody().getPosition().y}, {"Vida", vida} };
	};

	sf::Vector2f getPosicaoInicial() { return posicaoInicial; };

	bool getJogador2() { return jogador2; };
	bool getVoador() { return voador; };
};

