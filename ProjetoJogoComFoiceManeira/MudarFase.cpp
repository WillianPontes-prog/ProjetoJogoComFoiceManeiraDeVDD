#include "MudarFase.h"
#include "Jogo.h"

MudarFase::MudarFase(float posX, float posY, float tamX, float tamY, Jogo* jg):
	Entidade(posX, posY, tamX, tamY),
	jg(jg)
{
}

MudarFase::~MudarFase()
{
}

void MudarFase::atualiza()
{
	drawBody();
}

void MudarFase::executa()
{
	jg->setarModoDeJogo(Jogo::_fase2);
}
