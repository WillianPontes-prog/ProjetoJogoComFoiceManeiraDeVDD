#include "GerenciadorGrafico.h"

void GerenciadorGrafico::draw(Ente* e)
{
	window->draw(e->getSprite());
}
