#include "entityGenerator.h"


Jogador* EntityGenerator::createPlayer(float posX, float posY)
{
    return new Jogador(32,32,posX,posY);
}

Inimigo* EntityGenerator::createEnemy(float posX, float posY)
{
    return new Inimigo(32,32,posX,posY);
}

Plataforma* EntityGenerator::createPlatform(float posX, float posY)
{
    return new Plataforma(32,32,posX,posY);
}

EntityGenerator::EntityGenerator(Fase* _fase) : fase(_fase)
{
}

EntityGenerator::~EntityGenerator() 
{
}

void EntityGenerator::execute(float posX, float posY, int n)
{
	switch (n)
	{
	case 1313:
		fase->get_listaJogadores()->push_back(createPlayer(posX, posY));
		break;
	case 1337:
		fase->get_listaInimigos()->push_back(createEnemy(posX, posY));
		break;
	case 1317:
		fase->get_listaPlataforma()->push_back(createPlatform(posX, posY));
		break;
	default:
		
		break;
	}
}
