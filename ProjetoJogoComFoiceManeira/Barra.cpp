#include "Barra.h"

Barra::Barra(bool autom, float posX, float posY, float max, float at) :
	Entidade(80, 5, posX, posY),
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
	atual -= at;
	if (atual <= 0)
		return 1;
}

void Barra::atualiza() 
{
	body.setSize(sf::Vector2f((atual / maxima) * body.getSize().x, body.getSize().y));
	
	if(automatico){
		if (parado)
		{
			if (atual < maxima)
			{
				cura(0.5f);
			}
		}
	}
}
