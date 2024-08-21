#include "EntidadeColisao.h"

EntidadeColisao::EntidadeColisao(int posX, int posY, int vida) : 
	Entidade(posX, posY, 32, 32), 
	hspd(0), 
	vspd(0), 
	vida(vida)
{
}

EntidadeColisao::~EntidadeColisao()
{
}
