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
#include "BuilderArma.h"
#include "Projetil.h"
#include "ListaEntidade.h"
#include "MudarFase.h"

using namespace std;

using json = nlohmann::json;

namespace Listas {
	class ListaEntidade;
}

class Jogo;

namespace Gerenciadores { 
	class GerenciadorDeColisoes; 
}

namespace Fases{
	class Fase : public Ente
	{
	protected:

		Gerenciadores::GerenciadorDeColisoes* gerenciadorDeColisoes;

		sf::Texture* texturaFundo;
		sf::Sprite spriteFundo;
		bool Jogadores;

		Listas::ListaEntidade* listaEntidades;

		virtual void carregarFase() = 0;

		Jogo* jg;

		int numZumbinana[4];

		bool comPlataforma;

	public:
		Fase(bool Jogadores, Jogo* jg, bool continuar = 0);
		~Fase();

		bool continunando;


		Listas::Lista<Jogador*>* getListaJogadores();
		Listas::Lista<Obstaculos::Plataforma*>* getListaPlataforma();
		std::vector<Inimigo*>* getListaInimigos();
		std::list<Obstaculos::Obstaculo*>* getListaObstaculos();

		MudarFase* getMudarFase();
		void setMudarFase(MudarFase* m);

		void atualiza();
		virtual void criaEntidades(float posX, float posY, int n) = 0;

		json lerArquivoJSON(const std::string caminho);
		void gerarFase(vector<vector<vector<int>>> mapa);
		vector<vector<vector<int>>> extrairCamadas(const json& mapa, int numLayers);

		void setSpriteFundo(sf::Texture* texture);
		void setJogadores(bool jogadores) { Jogadores = jogadores; };

		void salvarFase();


		//------------metodos de criação de entidades-----------------\\
		================================================================
		void criarJogador(float posX = 0, float posY = 0, int vida = 5, bool j2 = false);

		void criarPlataforma(float posX = 0, float posY = 0, bool aleatoria = false);

		void criarMudarFase(float posX = 0, float posY = 0);

		void criarZumbinana(float posX = 0, float posY = 0, float vida = 5);





		void carregarProjeteis(float posX, float posY, float tamX, float tamY, int tempo, int velocidade, int dano, sf::Color cor, sf::Vector2f dir);

	};
}