#pragma once
#include "Entidade.h"
#include "Plataforma.h"
#include <list>
#include "Ataque.h"

class EntidadeColisao: public Entidade{

public:
	
	EntidadeColisao(float dimX = 100.f, float dimY = 100.f,float posX = 0, float posY = 0);
	~EntidadeColisao();

	void set_hspd(float hspd) { this->hspd = hspd; };
	void set_vspd(float vspd) { this->vspd = vspd; };

	float get_hspd() { return hspd; };
	float get_vspd() { return vspd; };

	void set_noChao(bool noChao) { this->noChao = noChao; }

	Lista<Ataque*>* get_listaAtaques() { return listaAtaques; }

protected:
	Lista<Plataforma*>* listPlat;

	float hspd = 0;
	float vspd = 0;

	float dir = 0;

	bool noChao = false;

	Lista<Ataque*>* listaAtaques;
};