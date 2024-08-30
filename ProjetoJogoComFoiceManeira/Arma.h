#pragma once
#include"Lista.h"
#include"Projetil.h"

class Arma {
private:
	Listas::Lista<Projetil*>* listaProjetil;
	int tempoDeRecarga;
	int tempoMaximo;
	int dano;
	int velocidade;
	sf::Color cor;
	sf::Vector2f tamanho;

public:
	Arma(int tempoDeRecarga = 8,int dano = 1, int tempoMaximo = 30 ,int velocidade=10, sf::Vector2f tamanho = sf::Vector2f(15, 10));
	~Arma();
	void disparar(sf::Vector2f posicao, sf::Vector2f direcao);
	int getTempoDeRecarga() { return tempoDeRecarga; };
	void setListaProjetil(Listas::Lista<Projetil*>* lista);
	void setCor(sf::Color c) { cor = c; }

	int getdano() { return dano; }

};