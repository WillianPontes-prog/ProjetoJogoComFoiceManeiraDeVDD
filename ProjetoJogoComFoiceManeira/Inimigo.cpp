#include "Inimigo.h"

Inimigo::Inimigo(float posX, float posY) :
	EntidadesColision()
{
	body.setFillColor(sf::Color::Cyan);
	body.setPosition(sf::Vector2f(posX, posY));
}

Inimigo::~Inimigo()
{
}

void Inimigo::atualiza()
{
	draw();
}
