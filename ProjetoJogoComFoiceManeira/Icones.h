#pragma once
#include"Ente.h"

class Icones : public Ente {

private:
	int quantidade;
	sf::Vector2f posicao;

public:
	Icones(sf::Vector2f posicao, int quantidade);
	~Icones();
	void draw();

};