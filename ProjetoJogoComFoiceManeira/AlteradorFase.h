#pragma once
#include"Iterativo.h"
using namespace std;

class AlteradorFase : public Iterativo {
private:
	//salva o nome de qual o jason da próxima fase;
	float prox;

public:
	AlteradorFase(float dimX = 200.f, float dimY = 200.f, float posX = 0, float posY = 0) : Iterativo(dimX, dimY, posX, posY) {}
	~AlteradorFase() {}
	
	float interacao() override { return prox; }

};