#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* GG):
	Fase(GG)
{
	setTextura("Imagens/BCK_fase1.png");
    gerarFase(extrairCamadas(lerArquivoJSON("pipipipopopodeteste.json"), 2));
}

Fase1::~Fase1()
{
}

void Fase1::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 1313:
        criaJogador(posX, posY);
        break;
    case 1337:
		criarInimigo1(posX, posY);
		break;
    case 1317:
        criaPlataforma(posX, posY);
        break;
    default:

    break;
    }
}
