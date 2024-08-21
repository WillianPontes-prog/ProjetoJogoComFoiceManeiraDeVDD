#include "Ente.h"

Ente::Ente() : gerenciadorGrafico(NULL)
{
}

Ente::~Ente()
{
}

void Ente::draw() {
	gerenciadorGrafico->draw(this);
}