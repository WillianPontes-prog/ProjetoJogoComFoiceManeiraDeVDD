#pragma once
#include "Entidade.h"
#include "Plataforma.h"
#include <list>


class EntidadeColisao: public Entidade{

public:
	
	std::list<Plataforma*>* get_listPlat();
	
	void set_listPlat(std::list<Plataforma*>* listPlat);

	EntidadeColisao(float dimX = 100.f, float dimY = 100.f,float posX = 0, float posY = 0, std::list<Plataforma*>* listPlat = nullptr);
	~EntidadeColisao();


protected:
	std::list<Plataforma*>* listPlat;

	float hspd = 0;
	float vspd = 0;

	float dir = 0;

};