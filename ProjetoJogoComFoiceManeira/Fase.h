#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Ataque.h"
#include "GeradorDeEntidade.h"
#include "Fase.h"
#include "json.hpp"
#include "Lista.h"
#include "GerenciadorDeColisao.h"
#include "GerenciadorGrafico.h"

using json = nlohmann::json;

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class GeradorDeEntidade;

class Fase {

private:
	
	
	Lista<Plataforma*>*		listaPlataforma;
	Lista<Jogador*>*	listaJogadores;
	Lista<Inimigo*>*	listaInimigos;
	Lista<Ataque*>*		listaAtaques;
	Lista<Ataque*>*		listaAtaquesInimigo;

	GerenciadorGrafico* gerenciadorGrafico;
	GerenciadorDeColisao* gerenciadorColisao;

	void inicializaElementos();

	std::string caminhoJson;
	GeradorDeEntidade* geradorDeEntidade;




public:
	Fase(sf::RenderWindow* window = nullptr, std::string caminhoJson = "");
	~Fase();

	sf::RenderWindow* window;

	Lista<Plataforma*>* get_listaPlataforma()	{ return listaPlataforma; }
	Lista<Jogador*>* get_listaJogadores()		{ return listaJogadores; }
	Lista<Inimigo*>* get_listaInimigos()		{ return listaInimigos; }
	Lista<Ataque*>* get_listaAtaques()			{ return listaAtaques; }
	Lista<Ataque*>* get_listaAtaquesInimigo()	{ return listaAtaquesInimigo; }

	void gerarFase();
	void atualiza();


	json lerArquivoJSON(const std::string caminho);

	vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

};