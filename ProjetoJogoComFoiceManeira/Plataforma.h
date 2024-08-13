#pragma once
#include "Entidade.h"

class Plataforma : public Entidade {

private:

public:
	Plataforma(float dimX = 32.f, float dimY = 32.f, float posX = 0, float posY = 0);
	~Plataforma();

	void atualiza() override {};
};
