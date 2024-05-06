#pragma once
#include "EntidadesColision.h"

class Jogador : public EntidadesColision {
private:
	float speedP = 3;

public:
	Jogador();
	~Jogador();

	void Move();

	void atualiza() override;

};