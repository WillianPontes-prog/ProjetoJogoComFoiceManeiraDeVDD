
#include "ObstaculoTeleporte.h"

ObstaculoTeleporte::ObstaculoTeleporte(sf::Vector2f posicao):
Obstaculo(posicao.x,posicao.y)
{
	
}

ObstaculoTeleporte::~ObstaculoTeleporte()
{
}

void ObstaculoTeleporte::atualiza()
{
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
	draw();
}

void ObstaculoTeleporte::Obstacular(Jogador* jogador)
{
	jogador->setPosition(jogador->getPosicaoInicial());
	jogador->setHspd(0);
	jogador->setVspd(0);

}
