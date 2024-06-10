#include "Plataforma.h"

Plataforma::Plataforma(float dimensionX, float dimensionY ,float posX, float posY):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	body.setFillColor(sf::Color::Red);
	
}

Plataforma::~Plataforma()
{
}
