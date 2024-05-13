#include "EntidadesColision.h"

ListaEntidade* EntidadesColision::get_LEs()
{
	return LEs;
}

void EntidadesColision::set_LEs(ListaEntidade* LEs)
{
	this->LEs = LEs;
}

EntidadesColision::EntidadesColision(float dimensionX, float dimensionY, ListaEntidade* LEs):
	Entidade(dimensionX, dimensionY)
{
	this->LEs = LEs;
}

EntidadesColision::~EntidadesColision()
{
}
