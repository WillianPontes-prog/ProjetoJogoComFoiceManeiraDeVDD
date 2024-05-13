#include "EntidadesColision.h"

std::list<Plataforma*>* EntidadesColision::get_listPlat()
{
	return listPlat;
}

void EntidadesColision::set_listPlat(std::list<Plataforma*>* listPlat)
{
	this->listPlat = listPlat;
}

EntidadesColision::EntidadesColision(float dimensionX, float dimensionY, std::list<Plataforma*>* listPlat):
	Entidade(dimensionX, dimensionY)
{
	this->listPlat = listPlat;
}

EntidadesColision::~EntidadesColision()
{
}
