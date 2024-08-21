#include "GerenciadorDeColisoes.h"

GerenciadorDeColisoes::GerenciadorDeColisoes(Fase* fase)
{
    this->fase = fase;
}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
}

void GerenciadorDeColisoes::tratarColisoes()
{
    //--itera sobre cada jogador--\\
    ================================

    Lista<Jogador*>* listaJogador = fase->getListaJogadores();
    Lista<Plataforma*>* listaPlataforma = fase->getListaPlataforma();

    for (Lista<Jogador*>::iterator itJog = listaJogador->begin(); itJog != listaJogador->end(); ++itJog) {


        sf::RectangleShape bodyTemp;

        //--seta por padrão que o jogador não está no chão--\\
        ====================================================
        (*itJog)->setNoChao(false);

        //--itera sobre todas plataformas--\\
        =====================================

        for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {

            //--percepção do jogador no chão--\\
            ===================================

            bodyTemp = (*itJog)->getBody();
            bodyTemp.move(sf::Vector2f(0, 1));

           if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                (*itJog)->setNoChao(true);
            }

            //--gerenciador de colisão--\\
            =============================

            bodyTemp = (*itJog)->getBody();
            bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), 0));

            if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                bodyTemp = (*itJog)->getBody();
                bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));

                while (!ChecarColisao(bodyTemp, (*it)->getBody())) {
                    (*itJog)->getBodyPtr()->move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));

                    bodyTemp = (*itJog)->getBody();
                    bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));
                }

                (*itJog)->setHspd(0);
            }

            bodyTemp = (*itJog)->getBody();
            bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), (*itJog)->getVspd()));

            if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                bodyTemp = (*itJog)->getBody();
                bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), NumeroMinimo((*itJog)->getVspd())));

                while (!ChecarColisao(bodyTemp, (*it)->getBody())) {
                    (*itJog)->getBodyPtr()->move(sf::Vector2f(0, NumeroMinimo((*itJog)->getVspd())));

                    bodyTemp = (*itJog)->getBody();
                    bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), NumeroMinimo((*itJog)->getVspd())));
                }

                (*itJog)->setVspd(0);
            }

        }

        (*itJog)->getBodyPtr()->move(sf::Vector2f((*itJog)->getHspd(), (*itJog)->getVspd()));

    }
}
