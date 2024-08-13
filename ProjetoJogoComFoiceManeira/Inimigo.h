#pragma once
#include "EntidadeColisao.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Arma.h"
#include "Jogador.h"
#include <cmath>

class Inimigo : public EntidadeColisao {

private:
	enum estadoDeInimigo {
		Normal,
		Atk
	};
	int state = Normal;

	int cooldown = 0;

	std::list<Ataque*>* listInimigoAtaque;
	Arma* armas[1];

	float velocidade = 3;
	std::list<Jogador*>* listaJogador;

public:
	Inimigo(float dimX = 100.f, float dimY = 100.f, float posX = 0.f, float posY = 0.f, std::list<Plataforma*>* listPlat = nullptr, std::list<Jogador*>* listJogador = nullptr);
	~Inimigo();

	void move();
	int procurarJogador();
	int procurarJogadorX();
	int tempoDeDestruicaoY();

	void atk();
	void atualiza() override;
	void set_listaJogador(std::list<Jogador*>* listJogador);
};
