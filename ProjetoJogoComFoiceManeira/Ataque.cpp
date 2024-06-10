#include "Ataque.h"

Ataque::Ataque(float dimensionX , float dimensionY , float posX , float posY ,float veloc, float dan, float dir):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	velocidade = veloc,
	dano = dan;
	direc = dir;
	body.setFillColor(sf::Color::Magenta);
	
}

void Ataque::Move()
{
	body.move(sf::Vector2f(std::cos(direc)*velocidade, std::sin(direc)*velocidade));
}

Ataque::~Ataque()
{
}


void Ataque::Atualiza()
{
	Move();
	draw();
}
