#include "Plataforma.h"

Plataforma::Plataforma(int posX, int posY)
	: Obstaculo(posX, posY), atrito(0.8f)
{
	
	atualizaSprite(posX, posY);
}

Plataforma::~Plataforma()
{

}

void Plataforma::atualiza()
{
	//drawBody();
}
