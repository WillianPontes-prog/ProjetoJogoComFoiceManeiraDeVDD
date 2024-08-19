#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico(
	sf::RenderWindow* _window, 
	Lista<Jogador*>* listaJogador,
	Lista<Inimigo*>* listaInimigo,
	Lista<Ataque*>* listaAtaque,
	Lista<Ataque*>* listaAtaqueInimigo)
	: 
	window(_window), 
	listaJogadores(listaJogador), 
	listaInimigos(listaInimigo), 
	listaAtaques(listaAtaque),
	listaAtaquesInimigo(listaAtaqueInimigo)
{
	//----------Carregando imagens e texturas----------\\
	=====================================================
	if (!toTexture.loadFromFile("Fase_1.png"))
		std::cerr << "Erro ao carregar a imagem!" << std::endl;

	toTile.setTexture(toTexture);

	//--------------------------------------------------\\

	if (!vidaTexture.loadFromFile("LifeImg.png"))
		std::cerr << "Erro ao carregar a imagem!" << std::endl;

	vidaTile.setTexture(vidaTexture);

	//--------------------------------------------------\\

	if(!backgroundTexture.loadFromFile("image_2024-08-19_113051706.png"))
		std::cerr << "Erro ao carregar a imagem!" << std::endl;

	backgroundTile.setTexture(backgroundTexture);
	//=================================================\\
	=====================================================
}

	GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::draw()
{
	//----desenha background----\\
	==============================
	window->draw(backgroundTile);

	//--desenha tile geral--\\
	==========================
	window->draw(toTile);

	//----desenha jogadores----\\
	=============================
	for(auto it = listaJogadores->begin(); it != listaJogadores->end(); it++)
	{
		window->draw((*it)->get_body());
		
		//----desenha vidas----\\
		=========================
		for (int i = 0; i < (*it)->get_vida(); i++) {
			vidaTile.setPosition(10 + (i * 32), 10);
			window->draw(vidaTile);
		}
	}
	//----desenha inimigos----\\
	=============================
	for(auto it = listaInimigos->begin(); it != listaInimigos->end(); it++)
	{
		window->draw((*it)->get_body());
	}

	//----desenha ataques----\\
	============================
	for(auto it = listaAtaques->begin(); it != listaAtaques->end(); it++)
	{
		window->draw((*it)->get_body());
	}

	//----desenha ataques inimigos----\\
	====================================
	for(auto it = listaAtaquesInimigo->begin(); it != listaAtaquesInimigo->end(); it++)
	{
		window->draw((*it)->get_body());
	}

}
