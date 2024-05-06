#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"

class Jogo {

private:
	sf::RenderWindow window;

	Jogador* Player1;

public:
	Jogo();
	~Jogo();

	void Atualiza();

};