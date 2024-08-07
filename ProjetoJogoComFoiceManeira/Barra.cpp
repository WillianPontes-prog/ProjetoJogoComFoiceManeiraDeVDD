#include "Barra.h"

Barra::Barra(float dimensionX, float dimensionY, float posX, float posY, float max, float at, bool autom) :
	Entidade(dimensionX, dimensionY, posX, posY),
	maxima(max),
	atual(at),
	automatico(autom)
{
	parado = 1;
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
	if(automatico){
		if (parado)
		{
			if (atual < maxima)
			{
				cura(5.0f);
			}
		}
	}
}
