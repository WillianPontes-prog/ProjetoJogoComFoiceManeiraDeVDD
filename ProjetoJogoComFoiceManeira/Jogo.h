#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Fase.h"

class Jogo {

private:
	sf::RenderWindow window;

	Jogador* Player1;

	ListaEntidade* LEs;

	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void Atualiza();

};