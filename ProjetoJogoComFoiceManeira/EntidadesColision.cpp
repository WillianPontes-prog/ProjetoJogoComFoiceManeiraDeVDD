#include "EntidadesColision.h"

ListaEntidade* EntidadesColision::get_LEs()
{
	return LEs;
}

void EntidadesColision::set_LEs(ListaEntidade* LEs)
{
	this->LEs = LEs;
}

EntidadesColision::EntidadesColision(ListaEntidade* LEs)
{
	this->LEs = LEs;
}

EntidadesColision::~EntidadesColision()
{
}
