#pragma once
#include "Arma.h"

class BuilderArma
{
private:
	Arma* arma;
public:
	BuilderArma() { arma = nullptr; };
	~BuilderArma() {};
	void buildArmaJogador1()  { arma = new Arma(8, 1, 35, 12, sf::Vector2f(8, 8)); };
	void buildArmaJogador2()  { arma = new Arma(16, 2, 80, 15, sf::Vector2f(15, 8)); };
	void buildArmaZumbinana() { arma = new Arma(80, 1, 30, 5, sf::Vector2f(15, 4)); };
	void buildArmaChefe()     { arma = new Arma(90, 1, 90, 4, sf::Vector2f(20, 10)); };
	void buildAmarelo() {
		if (arma) { arma->setCor(sf::Color::Yellow); };
	};
	void buildVermelho() {
		if (arma) { arma->setCor(sf::Color::Red); };
	};
	void buildRoxo() {
		if (arma) { arma->setCor(sf::Color::Magenta); };
	};
	void buildVerda() {
		if (arma) { arma->setCor(sf::Color::Green); };
	};
	void buildPreto() {
		if (arma) { arma->setCor(sf::Color::Black); };
	};
	void buildAzul() {
		if (arma) { arma->setCor(sf::Color::Blue); };
	};
	Arma* getArma() {
		return arma;
	};
};