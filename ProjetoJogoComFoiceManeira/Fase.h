#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "Ente.h"
#include "Lista.h"
#include "Jogador.h"
#include "Plataforma.h"
#include <vector>
#include "json.hpp"
#include "GerenciadorDeColisoes.h"
#include "Inimigo1.h"
#include "Inimigo2.h"
#include"Projetil.h"

using namespace std;

using json = nlohmann::json;

class GerenciadorDeColisoes;

class Fase : public Ente
{
protected:
	Lista<Jogador*>* listaJogadores;
	Lista<Plataforma*>* listaPlataformas;
	Lista<Inimigo*>* listaInimigos;
	Lista<Obstaculo*>* listaObstaculos;

	GerenciadorDeColisoes* gerenciadorDeColisoes;

	sf::Texture* texturaFundo;
	sf::Sprite spriteFundo;

public:
	Fase();
	~Fase();

	Lista<Jogador*>* getListaJogadores()		{ return listaJogadores; };
	Lista<Plataforma*>* getListaPlataforma()	{ return listaPlataformas; };
	Lista<Inimigo*>* getListaInimigos()			{ return listaInimigos; };
	Lista<Obstaculo*>* getListaObstaculos()		{ return listaObstaculos; };

	void atualiza();
	virtual void criaEntidades(float posX, float posY, int n) = 0;

	json lerArquivoJSON(const std::string caminho); 
	void gerarFase(vector<vector<vector<int>>> mapa);
	vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

	void setSpriteFundo(sf::Texture* texture);

	//------------metodos de cria��o de entidades-----------------\\
	================================================================
	void criaJogador(float posX = 0, float posY = 0, int vida = 5, bool j2 = false);

	void criaPlataforma(float posX = 0, float posY = 0);

	void criaFogo(float posX = 0, float posY = 0);	

	void criarInimigo1(float posX = 0, float posY = 0, float vida = 5);

	void criarInimigo2(float posX = 0, float posY = 0, float vida = 5);

};

