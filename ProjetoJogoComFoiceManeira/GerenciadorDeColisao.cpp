#include "GerenciadorDeColisao.h"

GerenciadorDeColisao::GerenciadorDeColisao(Lista<Jogador*>* jogadores, Lista<Inimigo*>* inimigos, Lista<Ataque*>* ataquesJogador, Lista<Ataque*>* ataquesInimigo, Lista<Plataforma*>* plataformas)
	: listaJogador(jogadores), listaInimigos(inimigos), listaAtaqueJogador(ataquesJogador), listaAtaqueInimigo(ataquesInimigo), listaPlataforma(plataformas)
{
}

GerenciadorDeColisao::~GerenciadorDeColisao()
{
}

void GerenciadorDeColisao::tratarColisoes()
{

}
