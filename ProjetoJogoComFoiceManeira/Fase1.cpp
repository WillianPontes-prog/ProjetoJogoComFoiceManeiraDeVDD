#include "Fase1.h"

Fase1::Fase1(bool Jogadores):
	Fase(Jogadores)
{
    setGerenciadorGrafico();
    gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaF1.json"), 2));
}

Fase1::~Fase1()
{
}

void Fase1::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2527:  //Jogador
        criaJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if(Jogadores)
            criaJogador(posX, posY, 5, true);
        break;
    case 2520:  //Inimigo1
		criarInimigo1(posX, posY);
		break;
    case 2505:  //Plataforma
        criaPlataforma(posX, posY);
        break;
    case 2511:  //tp
		criarObstaculo2(posX, posY);
        break;
    case 2522:  //Inimigo2
		criarInimigo2(posX, posY);
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