#include "Ataque.h"

Ataque::Ataque(float dimensionX , float dimensionY , float posX , float posY ,float veloc, float dir, float dan,  float TimeAtk):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	velocidade = veloc,
	dano = dan;
	direc = dir;
	body.setFillColor(sf::Color::Magenta);
	timeDestroy = TimeAtk;
	
	body.move(sf::Vector2f(-body.getSize().x / 2, -body.getSize().y/2));
}

void Ataque::Move()
{
	float cos = std::cos(direc);
	float sin = std::sin(direc);

	body.move(sf::Vector2f(cos*velocidade, sin*velocidade));                                                                                   

}

Ataque::~Ataque()
{
}


void Ataque::atualiza()
{
	
	Move();
	draw();

	timeDestroy--;
}

int Ataque::OverTime()
{
	if (timeDestroy <= 0) {
		return 1;
	}
	
	return 0;
}
