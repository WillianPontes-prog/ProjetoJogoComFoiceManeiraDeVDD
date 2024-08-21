#include "Fase.h"

Fase::Fase(GerenciadorGrafico* GG):
	listaJogadores(new Lista<Jogador*>()),
	Ente()
{
	this->setGerenciadorGrafico(GG);
}

Fase::~Fase()
{
}

void Fase::atualiza()
{
	draw();

	//--atualiza todos os jogadores--\\
	===================================
	for(Lista<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); it++)
	{
		(*it)->atualiza();
	}
}

void Fase::criaJogador(float posX, float posY, int vida)
{
	Jogador* j = new Jogador(posX, posY, vida);
	j->setGerenciadorGrafico(gerenciadorGrafico);

	listaJogadores->adicionarElemento(j);
}
