#pragma once

#include <SFML/Graphics.hpp>
#include <list>

#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Ataque.h"
class GerenciadorGrafico{

private:
	sf::RenderWindow* window;

	std::list<Jogador*>* listaJogadores;
	std::list<Inimigo*>* listaInimigos;
	std::list<Ataque*>* listaAtaques;
	std::list<Ataque*>* listaAtaquesInimigo;


	sf::Sprite vidaTile;
	sf::Texture vidaTexture;


	sf::Sprite toTile;
	sf::Texture toTexture;

	sf::Sprite backgroundTile;
	sf::Texture backgroundTexture;

public:
	GerenciadorGrafico(
		sf::RenderWindow* _window,
		std::list<Jogador*>* listaJogador,
		std::list<Inimigo*>* listaInimigo,
		std::list<Ataque*>* listaAtaque,
		std::list<Ataque*>* listaAtaqueInimigo);

	~GerenciadorGrafico();

	void draw();


	


};

