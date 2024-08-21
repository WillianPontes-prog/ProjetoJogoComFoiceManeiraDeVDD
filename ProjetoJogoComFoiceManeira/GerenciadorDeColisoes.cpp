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
    Lista<Inimigo*>* listaInimigos = fase->getListaInimigos();

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

    //--itera sobre cada inimigo--\\
   ================================
    for (Lista<Inimigo*>::iterator itIni = listaInimigos->begin(); itIni != listaInimigos->end(); ++itIni) {

        sf::RectangleShape bodyTemp;
       
    //==interação inimigo e jogador===========================================================================================================================================
    
        for(Lista<Jogador*>::iterator itJog = listaJogador->begin(); itJog != listaJogador->end(); ++itJog) {
			
            if((*itJog)->getState() == Jogador::Machucado) {
				continue;
			}

            bodyTemp = (*itIni)->getBody();
			bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), (*itIni)->getVspd()));

			if (ChecarColisao(bodyTemp, (*itJog)->getBody())) {
				
                float dirX = NumeroMinimo((*itJog)->getBody().getPosition().x - (*itIni)->getBody().getPosition().x);
                danoJogador(*itJog, dirX);

			}
		}

     
    //==interação inimigo e plataforma========================================================================================================================================
     
        //--seta por padrão que o inimigo não está no chão e o proximo passo no chao--\\
        ================================================================================
        (*itIni)->setNoChao(false);
        bool invertFlag = true;
        bool invertFlagY = true;
        Inimigo1* inimigo1 = dynamic_cast<Inimigo1*>(*itIni);

        //--itera sobre todas plataformas--\\
        =====================================
        for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {


            //--inverte a direção do inimigo--\\
            ====================================
            if (inimigo1) {
                bodyTemp = (*itIni)->getBody();
                bodyTemp.move(sf::Vector2f(NumeroMinimo((*itIni)->getHspd())*bodyTemp.getSize().x, 0));

                if(!ChecarColisao(bodyTemp, (*it)->getBody())) {
                    bodyTemp.move(sf::Vector2f(0, 1));

                    if(ChecarColisao(bodyTemp, (*it)->getBody()) && invertFlagY) {
                        invertFlag = false;
                        invertFlagY = false;
                    }
                }
                else {
                    invertFlag = true;
                    invertFlagY = false;
                }
            }

            //--gerenciador de colisão--\\
            =============================
            bodyTemp = (*itIni)->getBody();
            bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), 0));

            if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                bodyTemp = (*itIni)->getBody();
                bodyTemp.move(sf::Vector2f(NumeroMinimo((*itIni)->getHspd()), 0));

                while (!ChecarColisao(bodyTemp, (*it)->getBody())) {
                    (*itIni)->getBodyPtr()->move(sf::Vector2f(NumeroMinimo((*itIni)->getHspd()), 0));

                    bodyTemp = (*itIni)->getBody();
                    bodyTemp.move(sf::Vector2f(NumeroMinimo((*itIni)->getHspd()), 0));
                }

                (*itIni)->setHspd(0);
            }

            bodyTemp = (*itIni)->getBody();
            bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), (*itIni)->getVspd()));

            if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                bodyTemp = (*itIni)->getBody();
                bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), NumeroMinimo((*itIni)->getVspd())));

                while (!ChecarColisao(bodyTemp, (*it)->getBody())) {
                    (*itIni)->getBodyPtr()->move(sf::Vector2f(0, NumeroMinimo((*itIni)->getVspd())));

                    bodyTemp = (*itIni)->getBody();
                    bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), NumeroMinimo((*itIni)->getVspd())));
                }

                (*itIni)->setVspd(0);
            }

        }

        if (inimigo1 && invertFlag) {
            inimigo1->invertDirectionX();
        }

        (*itIni)->getBodyPtr()->move(sf::Vector2f((*itIni)->getHspd(), (*itIni)->getVspd()));

    //=========================================================================================================================================================================

    }
}

void GerenciadorDeColisoes::danoJogador(Jogador* jogador, int dirX)
{
    jogador->operator--();
    jogador->setState(Jogador::Machucado);

    jogador->setVspd(-10);
    jogador->setHspd(dirX * 8);
}
