#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* GG):
	Fase(GG)
{
	setTextura("Imagens/BCK_fase1.png");
    gerarFase(extrairCamadas(lerArquivoJSON("tileds/TiledFase1.json"), 2));
}

Fase1::~Fase1()
{
}

void Fase1::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2543:  //Jogador
        criaJogador(posX, posY, 5);
        break;
    case 2541:  //Jogador 2
        criaJogador(posX, posY, 5, true);
        break;
    case 2536:  //Inimigo1
		criarInimigo1(posX, posY);
		break;
    case 2521:  //Plataforma
        criaPlataforma(posX, posY);
        break;
    case 2527:  //Obstaculo2
		criarObstaculo2(posX, posY);
		break;
    default:

    break;
    }
}

void Fase1::criarObstaculo2(float posX, float posY)
{
    Obstaculo2* o = new Obstaculo2(sf::Vector2f(posX, posY));
    o->setGerenciadorGrafico(gerenciadorGrafico);

    listaObstaculos->adicionarElemento(o);
}
