#pragma once
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Plataforma.h"

#include <list>


class EntidadesColision: public Entidade{

public:
	
	std::list<Plataforma*>* get_listPlat();
	
	void set_listPlat(std::list<Plataforma*>* listPlat);

	EntidadesColision(float dimensionX = 100.f, float dimensionY = 100.f,float posX=0, float posY=0, std::list<Plataforma*>* listPlat = nullptr);
	~EntidadesColision();

protected:
	std::list<Plataforma*>* listPlat;

	float hspd = 0;
	float vspd = 0;

	float dir = 0;

};