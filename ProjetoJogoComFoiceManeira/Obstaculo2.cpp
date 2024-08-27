
#include "Obstaculo2.h"

Obstaculo2::Obstaculo2(sf::Vector2f posicao):
Obstaculo(posicao.x,posicao.y)
{
	
}

Obstaculo2::~Obstaculo2()
{
}

void Obstaculo2::atualiza()
{
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
	draw();
}

void Obstaculo2::teleporta(Jogador* jogador)
{
	
	jogador->setPosition(posicaoTelep);
}
