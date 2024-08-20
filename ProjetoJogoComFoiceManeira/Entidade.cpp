#include "Entidade.h"

Entidade::Entidade(float dimensionX, float dimensionY, float posX , float posY ) :
	body(sf::Vector2f(dimensionX, dimensionY))
{
	body.setPosition(sf::Vector2f(posX, posY));
}

Entidade::~Entidade()
{
}

sf::Vector2f Entidade::middleCenter()
{
	sf::Vector2f rtn;
	rtn.x = body.getPosition().x + (body.getSize().x / 2);
	rtn.y = body.getPosition().y + (body.getSize().y / 2);

	return rtn;
}
