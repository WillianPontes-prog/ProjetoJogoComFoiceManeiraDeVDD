#pragma once
#include "EntidadesColision.h"
#include "FIsica.h"
#include "Ataque.h"
#include "Weapons.h"
#include "Jogador.h"
#include <cmath>

class Inimigo : public EntidadesColision {

private:
	enum enemyState {
		Stand,
		Atk
	};
	int state = Stand;

	int cooldown = 0;

	std::list<Ataque*>* listInimigoAtaque;
	Weapons* armas[1];

	float speed = 3;
	std::list<Jogador*>* listJogador;

public:
	Inimigo(float dimensionX = 100.f, float dimensionY = 100.f, float posX = 0.f, float posY = 0.f, std::list<Plataforma*>* listPlat = nullptr, std::list<Jogador*>* listJogador = nullptr);
	~Inimigo();

	void move();
	int search();
	void atk();
	void atualiza() override;
	void set_listJogador(std::list<Jogador*>* listJogador);
};
