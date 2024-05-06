#pragma once
#include"Entidade.h"

class Inimigo : public Entidade {

private:

public:
	Inimigo(float posX = 0, float posY = 0);
	~Inimigo();

	void atualiza() override;
};
