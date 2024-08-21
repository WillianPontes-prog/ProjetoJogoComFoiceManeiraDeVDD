#include "Arma.h"

Arma::Arma(Lista<Projetil*>* listaProjetil, int tempoDeRecarga,int dano, int tempoMaximo, int velocidade, sf::Color c, sf::Vector2f tamanho):
	listaProjetil(listaProjetil),
	tempoDeRecarga(tempoDeRecarga),
	dano(dano),
	tempoMaximo(tempoMaximo),
	velocidade(velocidade),
	cor(c),
	tamanho(tamanho)
{
}

Arma::~Arma()
{
}

void Arma::disparar(sf::Vector2f posicao, sf::Vector2f direcao, GerenciadorGrafico* gg)
{
	Projetil* projetil = new Projetil(posicao.x, posicao.y, tamanho.x, tamanho.y, tempoMaximo, velocidade, dano, cor, direcao);
	projetil->setGerenciadorGrafico(gg);
	listaProjetil->adicionarElemento(projetil);
}


