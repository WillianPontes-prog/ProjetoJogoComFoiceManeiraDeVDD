#include "Barra.h"

Barra::Barra(float dimensionX, float dimensionY, float posX, float posY, float max, float at) :
	Entidade(dimensionX, dimensionY, posX, posY),
	maxima(max),
	atual(at)
{
}

Barra::~Barra()
{
}

bool Barra::dano(float at)
{
	atual-= at;
	if (atual <= 0)
		return 1;
}

void Barra::atualiza()
{
	body.setSize(sf::Vector2f((atual / maxima) * body.getSize().x, body.getSize().y));
	draw();
}
