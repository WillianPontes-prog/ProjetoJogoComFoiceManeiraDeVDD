#pragma once
#include "Entidade.h"

class Plataforma : public Entidade {

private:

public:
	Plataforma(float dimensionX = 100.f, float dimensionY = 100.f, float posX = 0, float posY = 0);
	~Plataforma();

};
