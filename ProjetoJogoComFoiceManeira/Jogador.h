#pragma once
#include "EntidadeColisao.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Tecla.h"
#include "Arma.h"
#include "Barra.h"

class Jogador : public EntidadeColisao {
private:

	
	int maxVida = 5;
	int vida = maxVida;

	Lista<Ataque*>* listaJogadorAtaque;
	Arma* armas[3];

	enum estadoDoJogador {
		Normal,
		Atk
	};

	int armatual;
	int state = Normal;

	float velocidadeP = 7;

	float pulo = 10;

	int flagPulo = 0;
	int flagArma = 0;	

	int coyteTime = 0;
	int MAXcoyteTime = 5;

	int cooldown = 0;


	/*
	Barra* vida;
	Barra* mana;
	//Barra stamina;
	//*/

public:
	Jogador(float dimX = 100.f, float dimY = 100.f, float posX = 0, float posY = 0, Lista<Plataforma*>* listPlat = nullptr);
	~Jogador();

	sf::Vector2f MidleButton() {
		sf::Vector2f rtn;
		rtn.x = body.getPosition().x + (body.getSize().x / 2);
		rtn.y = body.getPosition().y + body.getSize().y;
		return rtn;
	}

	void Move();

	void AtkBasico();

	void TrocarArma();

	Lista<Ataque*>* getListaAtk();

	void atualiza() override;

	int get_vida() { return vida; }
	int get_maxVida() { return maxVida; }

	void set_listaAtaques(Lista<Ataque*>* listaAtaques) { this->listaJogadorAtaque = listaAtaques; }

	
};