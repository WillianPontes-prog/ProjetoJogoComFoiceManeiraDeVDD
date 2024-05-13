#include "Plataforma.h"

Plataforma::Plataforma(float dimensionX, float dimensionY ,float posX, float posY):
	Entidade(dimensionX, dimensionY)
{
	body.setFillColor(sf::Color::Red);
	body.setPosition(sf::Vector2f(posX, posY));
}

Plataforma::~Plataforma()
{
}
