#include "Entidade.h"

Entidade::Entidade(float dimensionX, float dimensionY, float posX , float posY ) :
	body(sf::Vector2f(dimensionX, dimensionY)),
	window(NULL)
{
	body.setPosition(sf::Vector2f(posX, posY));
}

Entidade::~Entidade()
{
}

