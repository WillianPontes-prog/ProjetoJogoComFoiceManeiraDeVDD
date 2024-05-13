#include "Entidade.h"

Entidade::Entidade(float dimensionX, float dimensionY) :
	body(sf::Vector2f(dimensionX, dimensionY)),
	window(NULL)
{
	
}

Entidade::~Entidade()
{

}
