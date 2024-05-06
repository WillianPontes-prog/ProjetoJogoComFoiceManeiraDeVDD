#include "Plataforma.h"

Plataforma::Plataforma(float posX, float posY)
{
	body.setFillColor(sf::Color::Red);
	body.setPosition(sf::Vector2f(posX, posY));
}

Plataforma::~Plataforma()
{
}
