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
	float velocidade = 3;

	Lista<Jogador*>* listaJogador;
	Lista<Ataque*>* listInimigoAtaque;
	Arma* armas[1];

	bool proximoPassoNaPlatafortma = false;
	bool invert = false;


public:
	Inimigo(float dimX = 100.f, float dimY = 100.f, float posX = 0.f, float posY = 0.f, Lista<Plataforma*>* listPlat = nullptr, Lista<Jogador*>* listJogador = nullptr);
	~Inimigo();

	void move();
	int procurarJogador();
	int procurarJogadorX();
	int tempoDeDestruicaoY();

	void atk();
	void atualiza() override;
	void set_listaJogador(Lista<Jogador*>* listJogador);
	void set_listaAtaque(Lista<Ataque*>* listAtaque);

	void set_proximoPassoNaPlataforma(bool proximoPassoNaPlataforma) { this->proximoPassoNaPlatafortma = proximoPassoNaPlataforma; }
	void set_invert(bool invert) { this->invert = invert; }
};
