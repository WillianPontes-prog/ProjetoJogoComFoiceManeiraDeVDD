#pragma once
#include "Entidade.h"

class Plataforma : public Entidade {

private:

public:
	Plataforma(float dimensionX = 32.f, float dimensionY = 32.f, float posX = 0, float posY = 0);
	~Plataforma();

	void atualiza() override {};
};
