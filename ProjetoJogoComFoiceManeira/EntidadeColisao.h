#pragma once
#include "Entidade.h"
#include "Plataforma.h"
#include <list>


class EntidadeColisao: public Entidade{

public:
	
	Lista<Plataforma*>* get_listPlat();
	
	void set_listPlat(Lista<Plataforma*>* listPlat);

	EntidadeColisao(float dimX = 100.f, float dimY = 100.f,float posX = 0, float posY = 0, Lista<Plataforma*>* listPlat = nullptr);
	~EntidadeColisao();

	void set_hspd(float hspd) { this->hspd = hspd; };
	void set_vspd(float vspd) { this->vspd = vspd; };

	float get_hspd() { return hspd; };
	float get_vspd() { return vspd; };

	void set_noChao(bool noChao) { this->noChao = noChao; }

protected:
	Lista<Plataforma*>* listPlat;

	float hspd = 0;
	float vspd = 0;

	float dir = 0;

	bool noChao = false;

};