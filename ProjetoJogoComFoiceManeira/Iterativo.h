#pragma once
#include"Entidade.h"

using namespace std;
class Iterativo : public Entidade {
private:
 

public:
	virtual float interacao() = 0;
	Iterativo (float dimX = 200.f, float dimY = 200.f, float posX = 0, float posY = 0) : Entidade(dimX ,dimY, posX, posY) {}
	virtual ~Iterativo() {}
};