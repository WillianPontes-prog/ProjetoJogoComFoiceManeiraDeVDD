#include "GeradorDeEntidade.h"


Jogador* GeradorDeEntidade::criarJogador(float posX, float posY)
{
	Jogador* jogador = new Jogador(32, 32, posX, posY);
	jogador->set_Window(fase->window);
	jogador->set_listPlat(fase->get_listaPlataforma());
	jogador->set_listaAtaques(fase->get_listaAtaques());

	return jogador;
}

Inimigo* GeradorDeEntidade::criarInimigo(float posX, float posY)
{
	Inimigo* inimigo = new Inimigo(32, 32, posX, posY);
	inimigo->set_Window(fase->window);
	inimigo->set_listPlat(fase->get_listaPlataforma());
	inimigo->set_listaJogador(fase->get_listaJogadores());
	inimigo->set_listaAtaque(fase->get_listaAtaquesInimigo());

	return inimigo;
}

Plataforma* GeradorDeEntidade::criarPlataforma(float posX, float posY)
{
	Plataforma* plataforma = new Plataforma(32, 32, posX, posY);
	plataforma->set_Window(fase->window);

	return plataforma;
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
