#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

class Obstaculo2 : public Obstaculo {
private:
	sf::Vector2f posicao;
	sf::Vector2f posicaoTelep;

public:
	Obstaculo2(sf::Vector2f posicao);
	~Obstaculo2();

	void atualiza();
	void teleporta(Jogador* jogador);
};