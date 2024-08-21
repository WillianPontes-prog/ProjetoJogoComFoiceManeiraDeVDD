#pragma once
#include"Lista.h"
#include"Projetil.h"

class Arma {
	private:
		Lista<Projetil*>* listaProjetil;
		int tempoDeRecarga;
		int tempoMaximo;
		int dano;
		int velocidade;
		sf::Color cor;
		sf::Vector2f tamanho;
public:
			Arma(Lista<Projetil*>* listaProjetil, int tempoDeRecarga=8,int dano = 1, int tempoMaximo = 30 ,int velocidade=10, sf::Color c= sf::Color::White, sf::Vector2f tamanho = sf::Vector2f(15, 10));
			~Arma();
			void atira(sf::Vector2f posicao, sf::Vector2f direcao, GerenciadorGrafico* gg);
			void atualiza();
};