#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Fase.h"

#include<list>

class Jogo {

private:
	sf::RenderWindow window;

	Jogador* Player1;

	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>* listaJogadores;

	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void Atualiza();

};