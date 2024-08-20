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

	Lista<Jogador*>* listaJogadores;
	Lista<Inimigo*>* listaInimigos;
	Lista<Ataque*>* listaAtaques;
	Lista<Ataque*>* listaAtaquesInimigo;


	sf::Sprite vidaTile;
	sf::Texture vidaTexture;

	sf::Sprite toTile;
	sf::Texture toTexture;

	sf::Sprite backgroundTile;
	sf::Texture backgroundTexture;

public:
	GerenciadorGrafico(
		sf::RenderWindow* _window,
		Lista<Jogador*>* listaJogador,
		Lista<Inimigo*>* listaInimigo,
		Lista<Ataque*>* listaAtaque,
		Lista<Ataque*>* listaAtaqueInimigo);

	~GerenciadorGrafico();

	void draw();


	


};

