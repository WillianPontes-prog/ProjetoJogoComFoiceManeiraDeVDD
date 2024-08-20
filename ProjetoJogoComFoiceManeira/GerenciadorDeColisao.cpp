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

        //--itera sobre cada jogador--\\
        ================================
        for (Lista<Jogador*>::iterator itJog = listaJogador->begin(); itJog != listaJogador->end(); ++itJog) {

			sf::RectangleShape bodyTemp;

            //--seta por padr�o que o jogador n�o est� no ch�o--\\
            ====================================================
            (*itJog)->set_noChao(false);

            //--itera sobre todas plataformas--\\
            =====================================
            for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {
				
                //--percep��o do jogador no ch�o--\\
                ===================================
                bodyTemp = (*itJog)->body;
                bodyTemp.move(sf::Vector2f(0, 1));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    (*itJog)->set_noChao(true);
                }

                //--gerenciador de colis�o--\\
                =============================
                bodyTemp = (*itJog)->body;
                bodyTemp.move(sf::Vector2f((*itJog)->get_hspd(), 0));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    bodyTemp = (*itJog)->body;
                    bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->get_hspd()), 0));

                    while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
                        (*itJog)->body.move(sf::Vector2f(NumeroMinimo((*itJog)->get_hspd()), 0));

                        bodyTemp = (*itJog)->body;
                        bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->get_hspd()), 0));
                    }

                    (*itJog)->set_hspd(0);
                }

                bodyTemp = (*itJog)->body;
                bodyTemp.move(sf::Vector2f((*itJog)->get_hspd(), (*itJog)->get_vspd()));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    bodyTemp = (*itJog)->body;
                    bodyTemp.move(sf::Vector2f((*itJog)->get_hspd(), NumeroMinimo((*itJog)->get_vspd())));

                    while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
                        (*itJog)->body.move(sf::Vector2f(0, NumeroMinimo((*itJog)->get_vspd())));

                        bodyTemp = (*itJog)->body;
                        bodyTemp.move(sf::Vector2f((*itJog)->get_hspd(), NumeroMinimo((*itJog)->get_vspd())));
                    }

                    (*itJog)->set_vspd(0);
                }

			}

			(*itJog)->body.move(sf::Vector2f((*itJog)->get_hspd(), (*itJog)->get_vspd()));

        }
        
        
        //--itera sobre cada inimigo--\\
        ================================
        for (Lista<Inimigo*>::iterator itIni = listaInimigos->begin(); itIni != listaInimigos->end(); ++itIni) {

            sf::RectangleShape bodyTemp;
            bool invertFlag = true;

            //--seta por padr�o que o inimigo n�o est� no ch�o e o proximo passo no chao--\\
            ================================================================================
            (*itIni)->set_noChao(false);
            (*itIni)->set_proximoPassoNaPlataforma(false);


            //--itera sobre todas plataformas--\\
            =====================================
            for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {

                //--percep��o do inimigo no ch�o--\\
                ===================================
                bodyTemp = (*itIni)->body;
                bodyTemp.move(sf::Vector2f(0, 1));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    (*itIni)->set_noChao(true);
                }

                //--percep��o do inimigo no pr�ximo passo na plataforma--\\
                ===========================================================
                bodyTemp = (*itIni)->body;
                bodyTemp.move(sf::Vector2f((*itIni)->get_hspd() + ((*itIni)->body.getSize().x * (abs((*itIni)->get_hspd()) / (*itIni)->get_hspd())), 1));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    (*itIni)->set_proximoPassoNaPlataforma(true);
                }

                //--inverte a dire��o do inimigo--\\
                ====================================



                //--gerenciador de colis�o--\\
                =============================
                bodyTemp = (*itIni)->body;
                bodyTemp.move(sf::Vector2f((*itIni)->get_hspd(), 0));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    bodyTemp = (*itIni)->body;
                    bodyTemp.move(sf::Vector2f(NumeroMinimo((*itIni)->get_hspd()), 0));

                    while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
                        (*itIni)->body.move(sf::Vector2f(NumeroMinimo((*itIni)->get_hspd()), 0));

                        bodyTemp = (*itIni)->body;
                        bodyTemp.move(sf::Vector2f(NumeroMinimo((*itIni)->get_hspd()), 0));
                    }

                    (*itIni)->set_hspd(0);
                }

                bodyTemp = (*itIni)->body;
                bodyTemp.move(sf::Vector2f((*itIni)->get_hspd(), (*itIni)->get_vspd()));

                if (ChecarColisao(bodyTemp, (*it)->get_body())) {
                    bodyTemp = (*itIni)->body;
                    bodyTemp.move(sf::Vector2f((*itIni)->get_hspd(), NumeroMinimo((*itIni)->get_vspd())));

                    while (!ChecarColisao(bodyTemp, (*it)->get_body())) {
                        (*itIni)->body.move(sf::Vector2f(0, NumeroMinimo((*itIni)->get_vspd())));

                        bodyTemp = (*itIni)->body;
                        bodyTemp.move(sf::Vector2f((*itIni)->get_hspd(), NumeroMinimo((*itIni)->get_vspd())));
                    }

                    (*itIni)->set_vspd(0);
                }

            }

            (*itIni)->body.move(sf::Vector2f((*itIni)->get_hspd(), (*itIni)->get_vspd()));

        }
}
