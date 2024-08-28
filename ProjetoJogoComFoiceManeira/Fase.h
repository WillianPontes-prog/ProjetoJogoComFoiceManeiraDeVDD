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
#include "ZumbiFriorento.h"
#include "Zumbinana.h"
#include "Projetil.h"
#include "ListaEntidade.h"
#include "MudarFase.h"

using namespace std;

using json = nlohmann::json;

class ListaEntidade;

class Jogo;
class GerenciadorDeColisoes;



class Fase : public Ente
{
protected:

	GerenciadorDeColisoes* gerenciadorDeColisoes;

	sf::Texture* texturaFundo;
	sf::Sprite spriteFundo;
	bool Jogadores;

	ListaEntidade* listaEntidades;

	Jogo* jg;

public:
	Fase(bool Jogadores, Jogo* jg);
	~Fase();

	Lista<Jogador*>* getListaJogadores();
	Lista<Plataforma*>* getListaPlataforma();
	Lista<Inimigo*>* getListaInimigos();
	Lista<Obstaculo*>* getListaObstaculos();
	
	MudarFase* getMudarFase();
	void setMudarFase(MudarFase* m);

	void atualiza();
	virtual void criaEntidades(float posX, float posY, int n) = 0;

	json lerArquivoJSON(const std::string caminho); 
	void gerarFase(vector<vector<vector<int>>> mapa);
	vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

	void setSpriteFundo(sf::Texture* texture);
	void setJogadores(bool jogadores) { Jogadores = jogadores; };



	//------------metodos de criação de entidades-----------------\\
	================================================================
	void criarJogador(float posX = 0, float posY = 0, int vida = 5, bool j2 = false);

	void criarPlataforma(float posX = 0, float posY = 0);

	void criarMudarFase(float posX = 0, float posY = 0);

	void criarZumbinana(float posX = 0, float posY = 0, float vida = 5);

};

