#include "EntidadesColision.h"

std::list<Plataforma*>* EntidadesColision::get_listPlat()
{
	return listPlat;
}

void EntidadesColision::set_listPlat(std::list<Plataforma*>* listPlat)
{
	this->listPlat = listPlat;
}

EntidadesColision::EntidadesColision(float dimensionX, float dimensionY,float posX, float posY, std::list<Plataforma*>* listPlat):
	Entidade(dimensionX, dimensionY,posX, posY)
{
	this->listPlat = listPlat;
}

EntidadesColision::~EntidadesColision()
{
}
