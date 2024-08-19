#include "EntidadeColisao.h"

Lista<Plataforma*>* EntidadeColisao::get_listPlat()
{
	return listPlat;
}

void EntidadeColisao::set_listPlat(Lista<Plataforma*>* listPlat)
{
	this->listPlat = listPlat;
}

EntidadeColisao::EntidadeColisao(float dimensionX, float dimensionY,float posX, float posY, Lista<Plataforma*>* listPlat):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	this->listPlat = listPlat;
}

EntidadeColisao::~EntidadeColisao()
{
}
