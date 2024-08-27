#include "Fase1.h"

Fase1::Fase1(bool Jogadores):
	Fase(Jogadores)
{
    setGerenciadorGrafico();
    gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaFase1.json"), 2));
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
        if(Jogadores)
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
    case 2538:  //Inimigo2
		criarInimigo2(posX, posY);
		break;
    case 2525: //Plataforma
        criaFogo(posX, posY);
        break;
    default:

    break;
    }
}

void Fase1::criarObstaculo2(float posX, float posY)
{
    ObstaculoTeleporte* o = new ObstaculoTeleporte(sf::Vector2f(posX, posY));
    o->setGerenciadorGrafico();

    listaEntidades->incluir(o);
    getListaObstaculos()->adicionarElemento(o);
}

void Fase1::criarInimigo1(float posX, float posY, float vida)
{
    Inimigo1* i = new Inimigo1(getListaJogadores(), posX, posY, vida);
    i->setGerenciadorGrafico();

    listaEntidades->incluir(i);
    getListaInimigos()->adicionarElemento(i);
}