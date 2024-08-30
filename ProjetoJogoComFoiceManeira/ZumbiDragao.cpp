#include "ZumbiDragao.h"

using namespace Listas;

namespace Personagens {
	ZumbiDragao::ZumbiDragao(Lista<Jogador*>* listaJogadores, float posX, float posY, float vida, int chanceTeleporte, Arma* arma) :
		Inimigo(listaJogadores, posX, posY, vida, arma),
		chanceTeleporte(chanceTeleporte),
		posicao1(sf::Vector2f(posX, posY)),
		directionX(1)
	{
		body.setSize(sf::Vector2f(64, 64));
		tempoRecarregando = arma->getTempoDeRecarga();
	}

	ZumbiDragao::~ZumbiDragao()
	{
	}

	void ZumbiDragao::atualiza()
	{
		mudarCorDano();
		atualizaProjetil();
		draw();
		atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);

		sf::Vector2f posicao = BuscarJogador();
		Teleporte();
		move();
		if (std::abs(posicao.x) < 250 && std::abs(posicao.y) < 180) {
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

		sprite.setScale(-abs(directionX) / directionX, 1);

	}

	void ZumbiDragao::move()
	{
		//vazio ate que se diga o contrario
	}

	void ZumbiDragao::sacarArma()
	{
		direcao = BuscarJogador();
		disparar();
	}

	void ZumbiDragao::Teleporte()
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
}