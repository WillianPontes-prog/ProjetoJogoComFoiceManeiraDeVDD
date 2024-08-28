#include "Fase2.h"

void Fase2::carregarFase() {}

Fase2::Fase2(bool Jogadores, Jogo* jg, bool carregar) :
    Fase(Jogadores, jg, carregar),
    nChefao(0)
{
    setGerenciadorGrafico();

    if (!carregar)
        gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaF2.json"), 3));
    else
        carregarFase();
}

Fase2::~Fase2()
{
}

void Fase2::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2527:  //Jogador
        criarJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if (Jogadores)
            criarJogador(posX, posY, 5, true);
        break;
    case 2520:  //chefao
		criarChefao(posX, posY);
		break;
    case 2505:  //Plataforma
        criarPlataforma(posX, posY);
        break;
    case 2522:  //Inimigo2
        criarZumbinana(posX, posY);
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
    ZumbiDragao* chefao = new ZumbiDragao(getListaJogadores(), posX, posY, 40, 600, new Arma(90,1, 90, 10,sf::Color::Green,sf::Vector2f(20,10)));
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

