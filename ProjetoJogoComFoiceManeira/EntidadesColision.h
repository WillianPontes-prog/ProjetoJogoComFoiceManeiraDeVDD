#pragma once
#include "Entidade.h"
#include "ListaEntidade.h"

class EntidadesColision: public Entidade{

public:
	
	ListaEntidade* get_LEs();
	void set_LEs(ListaEntidade* LEs);

	EntidadesColision(ListaEntidade* LEs = nullptr);
	~EntidadesColision();

protected:
	ListaEntidade* LEs;


};