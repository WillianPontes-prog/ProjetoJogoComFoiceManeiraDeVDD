
#include "Obstaculo2.h"

Obstaculo2::Obstaculo2(sf::Vector2f posicao, sf::Vector2f posicaoTelep):
Obstaculo(posicao.x,posicao.y)
{
}

Obstaculo2::~Obstaculo2()
{
}

void Obstaculo2::atualiza()
{
	draw();
}

void Obstaculo2::teleporta(Jogador* jogador)
{
	jogador->setPosition(posicaoTelep);
}
