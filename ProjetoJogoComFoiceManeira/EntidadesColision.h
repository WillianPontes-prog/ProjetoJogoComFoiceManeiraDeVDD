#pragma once
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Plataforma.h"

#include <list>


class EntidadesColision: public Entidade{

public:
	
	std::list<Plataforma>* get_listPlat();
	
	void set_listPlat(std::list<Plataforma>* listPlat);

	EntidadesColision(float dimensionX = 100.f, float dimensionY = 100.f, std::list<Plataforma>* listPlat = nullptr);
	~EntidadesColision();

protected:
	std::list<Plataforma>* listPlat;


};