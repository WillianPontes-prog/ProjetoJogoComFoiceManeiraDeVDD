#include "Entidade.h"



Entidade::Entidade(float posX, float posY, float tamX, float tamY) : 
	Ente(), 
	body(sf::Vector2f(tamX, tamY))
{
	body.setPosition(sf::Vector2f(posX, posY));
}

Entidade::~Entidade()
{

}
