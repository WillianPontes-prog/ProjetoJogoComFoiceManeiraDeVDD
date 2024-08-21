#include "Plataforma.h"

Plataforma::Plataforma(int posX, int posY)
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
