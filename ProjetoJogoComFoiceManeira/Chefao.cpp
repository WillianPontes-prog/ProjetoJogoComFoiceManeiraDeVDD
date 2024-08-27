#include "Chefao.h"

Chefao::Chefao(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, int chanceTeleporte, Arma* arma):
	Inimigo(listaJogadores, posX, posY, vida,arma),
	chanceTeleporte(chanceTeleporte),
	posicao1(sf::Vector2f(posX, posY)),
	directionX(1)
{
	tempoRecarregando = arma->getTempoDeRecarga();
}

Chefao::~Chefao()
{
}

void Chefao::atualiza()
{
	atualizaProjetil();
	drawBody();
	sf::Vector2f posicao = BuscarJogador();
	Teleporte();
	move();
	if (std::abs(posicao.x) > 400 || std::abs(posicao.y) > 215) {
		if (tempoRecarregando == arma->getTempoDeRecarga()) {
			sacarArma();
		}
		tempoRecarregando--;
		if (tempoRecarregando <= 0) {
			tempoRecarregando = arma->getTempoDeRecarga();
		}
	}
	else
	{
		tempoRecarregando = arma->getTempoDeRecarga();
	}
	directionX = posicao.x > 0 ? 1 : -1;
	
	
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
		if (body.getPosition() == posicao1) {
			body.setPosition(posicao2);
			return;
		}
		body.setPosition(posicao1);
	}
}
