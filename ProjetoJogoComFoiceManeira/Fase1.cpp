#include "Fase1.h"

Fase1::Fase1(bool Jogadores, Jogo* jg, bool carregar):
	Fase(Jogadores, jg, carregar),
    numZumbiFriorento{0, 3, 5, 0}
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
        criarJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if(Jogadores)
            criarJogador(posX, posY, 5, true);
        break;
    case 2520:  //Inimigo1
        
		criarZumbiFriorento(posX, posY);
		break;
    case 2505:  //Plataforma
        criarPlataforma(posX, posY);
        break;
    case 2511:  //tp
		criarTeleporte(posX, posY);
        break;
    case 2522:  //Inimigo2
		criarZumbinana(posX, posY);
		break;
    case 2536:
        criarMudarFase(posX, posY);
        break;
    default:

    break;
    }
}

void Fase1::criarTeleporte(float posX, float posY)
{
    ObstaculoTeleporte* o = new ObstaculoTeleporte(sf::Vector2f(posX, posY));
    o->setGerenciadorGrafico();

    listaEntidades->incluir(o);
    getListaObstaculos()->adicionarElemento(o);
}

void Fase1::criarZumbiFriorento(float posX, float posY, float vida)
{

    int chance = rand() % 2;

    if(numZumbiFriorento[2] - numZumbiFriorento[3] <= numZumbiFriorento[1]){
        chance = 1;
	}
    

    if (numZumbiFriorento[0] > numZumbiFriorento[2]) {
        chance = 0;
    }

    if (chance) {
        ZumbiFriorento* i = new ZumbiFriorento(getListaJogadores(), posX, posY, vida);
        i->setGerenciadorGrafico();

        listaEntidades->incluir(i);
        getListaInimigos()->adicionarElemento(i);

        numZumbiFriorento[0]++;
    }

    numZumbiFriorento[3]++;
}