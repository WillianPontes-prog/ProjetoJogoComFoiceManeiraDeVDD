#include "Plataforma.h"

namespace Obstaculos {
	Plataforma::Plataforma(int posX, int posY, bool aleatoria)
		: Obstaculo(posX, posY), atrito(0.8f), aleatoria(aleatoria)
	{

		atualizaSprite(posX, posY);
	}

	Plataforma::~Plataforma()
	{

	}

	void Plataforma::atualiza()
	{
		if (aleatoria) {
			draw();
			atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
		}
	}

	void Plataforma::Obstacular(Personagens::Jogador* j)
	{
		j->setSobAtrito(true);
		j->setHspd(j->getHspd() * getAtrito());
	}
}