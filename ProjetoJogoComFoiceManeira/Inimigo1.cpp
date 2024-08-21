#include "Inimigo1.h"

Inimigo1::Inimigo1(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida):
	Inimigo(listaJogadores, posX, posY, vida)
{
	setTextura("Imagens/padraoSpr.png");
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
}
