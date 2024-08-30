#include "Arma.h"

using namespace Listas;
using namespace Entidades;

Arma::Arma(int tempoDeRecarga,int dano, int tempoMaximo, int velocidade, sf::Vector2f tamanho):
	tempoDeRecarga(tempoDeRecarga),
	dano(dano),
	tempoMaximo(tempoMaximo),
	velocidade(velocidade),
	tamanho(tamanho),
	listaProjetil(NULL)
{
}

Arma::~Arma()
{
}

void Arma::disparar(sf::Vector2f posicao, sf::Vector2f direcao)
{
	Projetil* projetil = new Projetil(posicao.x - (tamanho.x/2), posicao.y - (tamanho.y/2), tamanho.x, tamanho.y, tempoMaximo, velocidade, dano, cor, direcao);
	projetil->setGerenciadorGrafico();
	listaProjetil->adicionarElemento(projetil);

}

void Arma::setListaProjetil(Listas::Lista<Projetil*>* lista)
{
	listaProjetil = lista;
}

