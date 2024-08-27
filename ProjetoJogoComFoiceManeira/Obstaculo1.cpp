#include "Obstaculo1.h"

void Obstaculo1::atualiza()
{
	draw();
	atualizaSprite(getBody().getPosition().x, getBody().getPosition().y);
}
