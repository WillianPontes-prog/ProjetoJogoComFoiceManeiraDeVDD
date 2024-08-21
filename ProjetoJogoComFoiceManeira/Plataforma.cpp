#include "Plataforma.h"

Plataforma::Plataforma(int posX, int posY)
	: Obstaculo(posX, posY)
{
	setTextura("Imagens/padraoSpr.png");
	atualizaSprite(posX, posY);
}

Plataforma::~Plataforma()
{
}

void Plataforma::atualiza()
{
	
	draw();
}
