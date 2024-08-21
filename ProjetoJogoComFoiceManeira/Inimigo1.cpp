#include "Inimigo1.h"

Inimigo1::Inimigo1(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida):
	Inimigo(listaJogadores, posX, posY, vida),
	directionX(1)
{
	setTextura("Imagens/padraoSpr.png");
	velocidade = 1;

	if(!(rand() % 2))
		directionX = -1;
}

Inimigo1::~Inimigo1()
{
}

void Inimigo1::atualiza()
{
	move();
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
	draw();
}

void Inimigo1::move()
{

	hspd = velocidade * directionX;
	vspd += GRAVIDADE;
}
