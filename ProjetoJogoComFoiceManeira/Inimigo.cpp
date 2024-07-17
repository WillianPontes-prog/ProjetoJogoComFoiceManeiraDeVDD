#include "Inimigo.h"

Inimigo::Inimigo(float dimensionX, float dimensionY, float posX, float posY, std::list<Plataforma*>* listPlat) :
	EntidadesColision(dimensionX, dimensionY, posX, posY, listPlat)
{
	body.setFillColor(sf::Color::Cyan);
	body.setPosition(sf::Vector2f(posX, posY));

	listInimigoAtaque = new std::list<Ataque*>();

}

Inimigo::~Inimigo()
{
}

void Inimigo::move()
{
}


void Inimigo::search()
{
	char found=0;

	if (found){
		
		if (found > 0) {
			Ataque* hit = armas[0]->atack(get_body().getPosition().x, get_body().getPosition().y, 1);
			hit->set_Window(window);
			listInimigoAtaque->push_back(hit);
		}
		else {
			Ataque* hit = armas[1]->atack(get_body().getPosition().x, get_body().getPosition().y, 1);
			hit->set_Window(window);
			listInimigoAtaque->push_back(hit);
		}
		
	}
}

void Inimigo::atualiza()
{
	search();
	move();
	draw();
}


