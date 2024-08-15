#pragma once
#include"Entidade.h"

using namespace std;
class Iterativo : public Entidade {
private:
	sf::ConvexShape triangulo;
	

public:
	virtual float interacao() = 0;
	Iterativo (float dimX = 200.f, float dimY = 200.f, float posX = 0, float posY = 0) : Entidade(dimX ,dimY, posX, posY) {
		triangulo.setPointCount(3);
		triangulo.setPoint(0, sf::Vector2f(posX + 16, posY - 60));  // Ponto superior
		triangulo.setPoint(1, sf::Vector2f(posX, posY - 50));  // Ponto inferior esquerdo
		triangulo.setPoint(2, sf::Vector2f(posX + 32, posY - 50));  // Ponto inferior direito
	}
	 virtual ~Iterativo() {}
	 void Iterage(sf::RenderWindow* window)  {
		window->draw(triangulo);
	}
};