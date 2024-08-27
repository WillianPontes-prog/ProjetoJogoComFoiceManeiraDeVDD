#pragma once
#include "Fase.h"

class Fase2 : public Fase
{
protected:

public:
	Fase2(bool Jogadores);
	~Fase2();

	void criaEntidades(float posX, float posY, int n);


};

