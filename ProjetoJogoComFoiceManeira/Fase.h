#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Ataque.h"
#include "GeradorDeEntidade.h"
#include "json.hpp"
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
	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>*	listaJogadores;
	std::list<Inimigo*>*	listaInimigos;
	std::list<Ataque*>*		listaAtaques;
	std::list<Ataque*>*		listaAtaquesInimigo;

	GerenciadorGrafico* gerenciadorGrafico;

	void inicializaElementos();

	std::string caminhoJson;
	GeradorDeEntidade* geradorDeEntidade;




public:
	Fase(sf::RenderWindow* window = nullptr, std::string caminhoJson = "");
	~Fase();

	sf::RenderWindow* window;
	std::list<Plataforma*>* get_listaPlataforma() { return listaPlataforma; }
	std::list<Jogador*>* get_listaJogadores() { return listaJogadores; }
	std::list<Inimigo*>* get_listaInimigos() { return listaInimigos; }
	std::list<Ataque*>* get_listaAtaques() { return listaAtaques; }
	std::list<Ataque*>* get_listaAtaquesInimigo() { return listaAtaquesInimigo; }

	void gerarFase();
	void atualiza();


	json lerArquivoJSON(const std::string caminho);

	vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

};