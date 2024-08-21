#pragma once
#include"Entidade.h"
#include <cmath>
class Projetil : public Entidade {
private:
	float velocidad;
	int dano, tempo;
	sf::Vector2f direcao;


	int tempoDeDestruicao;
	

public:
	Projetil(float posX = 0, float posY = 0, float tamX = 10, float tamY = 15, int tempo= 15, int velocidade=8, int dano=1,sf::Color c = sf::Color::White, sf::Vector2f direc = sf::Vector2f(1,0));
	~Projetil();
	void Move();
	void atualiza();
	
	int OverTime();

};