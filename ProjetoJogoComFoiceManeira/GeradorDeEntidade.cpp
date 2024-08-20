#include "GeradorDeEntidade.h"


Jogador* GeradorDeEntidade::criarJogador(float posX, float posY)
{
	Jogador* jogador = new Jogador(32, 32, posX, posY);

	return jogador;
}

Inimigo* GeradorDeEntidade::criarInimigo(float posX, float posY)
{
	Inimigo* inimigo = new Inimigo(32, 32, posX, posY);
	inimigo->set_listaJogador(fase->get_listaJogadores());

	return inimigo;
}

Plataforma* GeradorDeEntidade::criarPlataforma(float posX, float posY)
{
	Plataforma* plataforma = new Plataforma(32, 32, posX, posY);

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
		fase->get_listaJogadores()->adicionarElemento(criarJogador(posX, posY));
		break;
	case 1337:
		fase->get_listaInimigos()->adicionarElemento(criarInimigo(posX, posY));
		break;
	case 1317:
		fase->get_listaPlataforma()->adicionarElemento(criarPlataforma(posX, posY));
		break;
	default:
		
		break;
	}
}
