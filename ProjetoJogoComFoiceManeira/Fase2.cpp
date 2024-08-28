#include "Fase2.h"

Fase2::Fase2(bool Jogadores) :
    Fase(Jogadores),
    nChefao(0)
{
    setGerenciadorGrafico();
    gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaF2.json"), 3));
}

Fase2::~Fase2()
{
}

void Fase2::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2527:  //Jogador
        criaJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if (Jogadores)
            criaJogador(posX, posY, 5, true);
        break;
    case 2520:  //chefao
		criarChefao(posX, posY);
		break;
    case 2505:  //Plataforma
        criaPlataforma(posX, posY);
        break;
    case 2522:  //Inimigo2
        criarInimigo2(posX, posY);
        break;
    case 2511: //Fogo
        criaFogo(posX, posY);
        break;
    default:

        break;
    }
}

void Fase2::criarChefao(float posX, float posY)
{
    Chefao* chefao = new Chefao(getListaJogadores(), posX, posY, 40, 600, new Arma(30));
    chefao->setGerenciadorGrafico();

    sf::Vector2f pos = sf::Vector2f(25*32, 13*32);

    if(nChefao == 1){
        pos = sf::Vector2f(15*32, 5*32);
    }

    chefao->setPosicao2(pos);
	listaEntidades->incluir(chefao);
	getListaInimigos()->adicionarElemento(chefao);

    nChefao++;
}

void Fase2::criaFogo(float posX, float posY)
{
    ObstaculoDano* o = new ObstaculoDano(posX, posY, 1);
    o->setGerenciadorGrafico();

    listaEntidades->incluir(o);
    getListaObstaculos()->adicionarElemento(o);
}

