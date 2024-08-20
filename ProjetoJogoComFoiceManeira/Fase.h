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
#include "Ente.h"

using namespace std;

class GerenciadorDeColisao;

class Fase : public Ente{

private:
	
	
	Lista<Plataforma*>*		listaPlataforma;
	Lista<Jogador*>*		listaJogadores;
	Lista<Inimigo*>*		listaInimigos;

	static GerenciadorGrafico* gerenciadorGrafico;
	GerenciadorDeColisao* gerenciadorColisao;

	void inicializaElementos();

	std::string caminhoJson;

	Jogador* criarJogador(float posX, float posY);
	Inimigo* criarInimigo(float posX, float posY);
	Plataforma* criarPlataforma(float posX, float posY);

public:
	Fase(std::string caminhoJson = "");
	~Fase();


	sf::RenderWindow* window;

	Lista<Plataforma*>* get_listaPlataforma()	{ return listaPlataforma; }
	Lista<Jogador*>* get_listaJogadores()		{ return listaJogadores; }
	Lista<Inimigo*>* get_listaInimigos()		{ return listaInimigos; }

	void gerarFase();
	void atualiza();


	json lerArquivoJSON(const std::string caminho);

	vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

};