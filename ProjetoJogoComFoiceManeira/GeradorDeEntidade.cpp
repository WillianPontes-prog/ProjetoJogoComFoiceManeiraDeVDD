#include "GeradorDeEntidade.h"


Jogador* GeradorDeEntidade::criarJogador(float posX, float posY)
{
    return new Jogador(32,32,posX,posY);
}

Inimigo* GeradorDeEntidade::criarInimigo(float posX, float posY)
{
    return new Inimigo(32,32,posX,posY);
}

Plataforma* GeradorDeEntidade::criarPlataforma(float posX, float posY)
{
    return new Plataforma(32,32,posX,posY);
}

GeradorDeEntidade::GeradorDeEntidade(Fase* _fase) : fase(_fase)
{
}

GeradorDeEntidade::~GeradorDeEntidade() 
{
}

void GeradorDeEntidade::executar(float posX, float posY, int n)
{
	switch (n)
	{
	case 1313:
		fase->get_listaJogadores()->push_back(criarJogador(posX, posY));
		break;
	case 1337:
		fase->get_listaInimigos()->push_back(criarInimigo(posX, posY));
		break;
	case 1317:
		fase->get_listaPlataforma()->push_back(criarPlataforma(posX, posY));
		break;
	default:
		
		break;
	}
}
