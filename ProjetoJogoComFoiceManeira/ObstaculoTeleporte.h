#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

class ObstaculoTeleporte : public Obstaculo {
private:
	sf::Vector2f posicao;
	sf::Vector2f posicaoTelep;

public:
	ObstaculoTeleporte(sf::Vector2f posicao);
	~ObstaculoTeleporte();

	void atualiza();
	void Obstacular(Jogador* jogador);
	json toJson() {
		return json{
		{classe, Tipo::_obstaculoTeleporte},
		{pX, getBody().getPosition().x},
		{pY, getBody().getPosition().y}
		};
	}
};