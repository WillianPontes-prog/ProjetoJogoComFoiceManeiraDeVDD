#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

#include "Ente.h"
#include "Listas/Lista.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include <vector>
#include "json.hpp"
#include "Gerenciadores/GerenciadorDeColisoes.h"
#include "Entidades/Personagens/ZumbiFriorento.h"
#include "Entidades/Personagens/Zumbinana.h"
#include "BuilderArma.h"
#include "Entidades/Projetil.h"
#include "Listas/ListaEntidade.h"
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


		Listas::Lista<Entidades::Personagens::Jogador*>* getListaJogadores();
		Listas::Lista<Entidades::Obstaculos::Plataforma*>* getListaPlataforma();
		std::vector<Entidades::Personagens::Inimigo*>* getListaInimigos();
		std::list<Entidades::Obstaculos::Obstaculo*>* getListaObstaculos();

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


		//------------metodos de cria��o de entidades-----------------\\
		================================================================
		void criarJogador(float posX = 0, float posY = 0, int vida = 5, bool j2 = false);

		void criarPlataforma(float posX = 0, float posY = 0, bool aleatoria = false);

		void criarMudarFase(float posX = 0, float posY = 0);

		void criarZumbinana(float posX = 0, float posY = 0, float vida = 5);





		void carregarProjeteis(float posX, float posY, float tamX, float tamY, int tempo, int velocidade, int dano, sf::Color cor, sf::Vector2f dir);

	};
}