#include "Plataforma.h"

Plataforma::Plataforma(int posX, int posY)
	: Obstaculo(posX, posY), atrito(0.8f)
{
	setTextura("Imagens/padraoSpr.png");
	atualizaSprite(posX, posY);
}

Plataforma::~Plataforma()
{

}

void Plataforma::atualiza()
{
	drawBody();
}
