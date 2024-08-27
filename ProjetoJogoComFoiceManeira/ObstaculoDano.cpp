#include "ObstaculoDano.h"

void ObstaculoDano::atualiza()
{
	draw();
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
}

void ObstaculoDano::Obstacular(Jogador* j)
{
	j->operator--();
}
