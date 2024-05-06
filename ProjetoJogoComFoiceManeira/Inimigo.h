#pragma once
#include"EntidadesColision.h"

class Inimigo : public EntidadesColision {

private:

public:
	Inimigo(float posX = 0, float posY = 0);
	~Inimigo();

	void atualiza() override;
};
