#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"

class Jogador : public EntidadesColision {
private:
	float speedP = 6;

public:
	Jogador();
	~Jogador();

	void Move();

	void atualiza() override;

};