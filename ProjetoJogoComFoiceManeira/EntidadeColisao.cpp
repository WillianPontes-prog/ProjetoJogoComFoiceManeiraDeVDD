#include "EntidadeColisao.h"

std::list<Plataforma*>* EntidadeColisao::get_listPlat()
{
	return listPlat;
}

void EntidadeColisao::set_listPlat(std::list<Plataforma*>* listPlat)
{
	this->listPlat = listPlat;
}

EntidadeColisao::EntidadeColisao(float dimensionX, float dimensionY,float posX, float posY, std::list<Plataforma*>* listPlat):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	this->listPlat = listPlat;
}

EntidadeColisao::~EntidadeColisao()
{
}
