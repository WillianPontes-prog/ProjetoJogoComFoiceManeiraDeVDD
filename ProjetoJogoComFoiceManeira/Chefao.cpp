#include "Chefao.h"

Chefao::Chefao(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, int chanceTeleporte, Arma* arma):
	Inimigo(listaJogadores, posX, posY, vida,arma),
	chanceTeleporte(chanceTeleporte),
	posicao1(sf::Vector2f(posX, posY))
{
	
}

Chefao::~Chefao()
{
}

void Chefao::atualiza()
{
	Teleporte();
	move();
	sacarArma();
}

void Chefao::move()
{
	//vazio ate que se diga o contrario
}

void Chefao::sacarArma()
{
	direcao = BuscarJogador();
	disparar();
}

void Chefao::Teleporte()
{
	if (rand() % chanceTeleporte == 0)
	{
		
	}
}
