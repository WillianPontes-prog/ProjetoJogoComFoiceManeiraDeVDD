#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Weapons.h"

class Inimigo : public EntidadesColision {

private:
	std::list<Ataque*>* listInimigoAtaque;
	Weapons* armas[2];
public:
	Inimigo(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat);
	~Inimigo();

	void move();
	void search();
	void atualiza() override;
};
