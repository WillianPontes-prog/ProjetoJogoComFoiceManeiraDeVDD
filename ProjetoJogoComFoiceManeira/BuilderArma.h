#pragma once
#include "Arma.h"

class BuilderArma
{
private:
	Arma* arma;
public:
	BuilderArma() { arma = nullptr; };
	~BuilderArma() {};
	void buildArmaJogador1()  { arma = new Arma(8, 1, 35, 12, sf::Color::White, sf::Vector2f(8, 8)); };
	void buildArmaJogador2()  { arma = new Arma(16, 2, 80, 15, sf::Color::White, sf::Vector2f(15, 8)); };
	void buildArmaZumbinana() { arma = new Arma(80, 1, 30, 5, sf::Color::Red, sf::Vector2f(15, 4)); };
	void buildArmaChefe()     { arma = new Arma(90, 1, 90, 10, sf::Color::Green, sf::Vector2f(20, 10)); };
	void buildAmarelo() {
		if (arma) { arma->setCor(sf::Color::White); };
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
	Arma* getArma() {
		return arma;
	};
};