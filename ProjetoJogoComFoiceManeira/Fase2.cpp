#include "Fase2.h"

Fase2::Fase2(bool Jogadores) :
    Fase(Jogadores)
{
    setGerenciadorGrafico();
    gerarFase(extrairCamadas(lerArquivoJSON("tileds/Fase_2.json"), 3));
}

Fase2::~Fase2()
{
}

void Fase2::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2543:  //Jogador
        criaJogador(posX, posY, 5);
        break;
    case 2541:  //Jogador 2
        if (Jogadores)
            criaJogador(posX, posY, 5, true);
        break;
    case 2521:  //Plataforma
        criaPlataforma(posX, posY);
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


