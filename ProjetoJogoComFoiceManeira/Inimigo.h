#pragma once
#include "EntidadeColidivel.h"
#include "Jogador.h"
#include "Lista.h"

class Inimigo : public EntidadeColidivel {

protected:
	Listas::Lista<Jogador*>* listaJogadores;

	

public:
	Inimigo(Listas::Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5, Arma* arma = nullptr);
	~Inimigo();

	sf::Vector2f BuscarJogador();

	virtual void atualiza() = 0;

	virtual void move() = 0;

	virtual void sacarArma() = 0;

	virtual void danificar(Jogador* j) = 0;

	void operator--(int dan) { vida-= dan; tempoMachucado = maxTempoMachucado; }

	virtual json toJson() = 0;

	void mudarCorDano() {
		if (tempoMachucado > 0) {
			sprite.setColor(sf::Color::Black);
			tempoMachucado--;
		}
		else {
			sprite.setColor(sf::Color::White);
		}
	}
};

