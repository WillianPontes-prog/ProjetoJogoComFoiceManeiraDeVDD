#include "Arma.h"

Arma::Arma(int tempoDeRecarga,int dano, int tempoMaximo, int velocidade, sf::Color c, sf::Vector2f tamanho):
	tempoDeRecarga(tempoDeRecarga),
	dano(dano),
	tempoMaximo(tempoMaximo),
	velocidade(velocidade),
	cor(c),
	tamanho(tamanho),
	listaProjetil(NULL)
{
}

Arma::~Arma()
{
}

void Arma::disparar(sf::Vector2f posicao, sf::Vector2f direcao, GerenciadorGrafico* gg)
{
	Projetil* projetil = new Projetil(posicao.x - (tamanho.x/2), posicao.y - (tamanho.y/2), tamanho.x, tamanho.y, tempoMaximo, velocidade, dano, cor, direcao);
	projetil->setGerenciadorGrafico(gg);
	listaProjetil->adicionarElemento(projetil);

}


