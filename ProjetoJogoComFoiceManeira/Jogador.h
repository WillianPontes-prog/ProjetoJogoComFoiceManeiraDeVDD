#pragma once
#include "EntidadeColidivel.h"
#include "Observer.h"


class Jogador : public EntidadeColidivel, public Observer
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

	bool vivo;

	int WASD[4];
	int gun;

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
		return json{ { classe, T}, { pX, getBody().getPosition().x},  { pY, getBody().getPosition().y}, { vd, vida} };
	};

	sf::Vector2f getPosicaoInicial() { return posicaoInicial; };

	bool getJogador2() { return jogador2; };
	bool getVoador() { return voador; };

	void onNotify(int tecla) override {
		switch (tecla) {
		case sf::Keyboard::W:
			if (!jogador2)
				WASD[0] = 1;
			break;
		case sf::Keyboard::A:
			if (!jogador2)
				WASD[1] = 1;
			break;
		case sf::Keyboard::S:
			if (!jogador2)
				WASD[2] = 1;
			break;
		case sf::Keyboard::D:
			if (!jogador2)
				WASD[3] = 1;
			break;
		case sf::Keyboard::F:
			if (!jogador2)
				gun = 1;
			break;
		case sf::Keyboard::Up:
			if (jogador2)
				WASD[0] = 1;
			break;
		case sf::Keyboard::Left:
			if (jogador2)
				WASD[1] = 1;
			break;
		case sf::Keyboard::Down:
			if (jogador2)
				WASD[2] = 1;
			break;
		case sf::Keyboard::Right:
			if (jogador2)
				WASD[3] = 1;
			break;
		case sf::Keyboard::M:
			if (jogador2)
				gun = 1;
			break;

		default:
			WASD[0] = 0;
			WASD[1] = 0;
			WASD[2] = 0;
			WASD[3] = 0;
			gun = 0;
			break;
		}
	}
};

