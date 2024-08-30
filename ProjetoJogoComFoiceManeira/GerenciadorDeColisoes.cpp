#include "GerenciadorDeColisoes.h"
#include "Jogo.h"
#include "MudarFase.h"


GerenciadorDeColisoes::GerenciadorDeColisoes(Fase* fase):
    listaJogador(new Lista<Jogador*>()),
    listaPlataforma(new Lista<Plataforma*>()),
    listaInimigos(new std::vector<Inimigo*>()),
    listaObstaculos(new std::list<Obstaculo*>()),
    mudarFase(nullptr)
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


    for (Lista<Jogador*>::iterator itJog = listaJogador->begin(); itJog != listaJogador->end(); ++itJog) {

        if (mudarFase) {
            if (ChecarColisao((*itJog)->getBody(), mudarFase->getBody())) {
                mudarFase->executa();
            }
        }

        sf::RectangleShape bodyTemp;
        //--seta por padrão que o jogador não está no chão--\\
        ====================================================
        (*itJog)->setNoChao(false);

        //--colisão Jogador com jogador--\\
        ===================================

        for (Lista<Jogador*>::iterator itJogColider = listaJogador->begin(); itJogColider != listaJogador->end(); ++itJogColider) {
            
            if ((*itJog) != (*itJogColider)) {
                
                //--percepção do jogador com jogador--\\
                ========================================

                bodyTemp = (*itJog)->getBody();
                bodyTemp.move(sf::Vector2f(0, 1));

                if (ChecarColisao(bodyTemp, (*itJogColider)->getBody())) {
                   (*itJog)->setNoChao(true);
                }

                //--gerenciador de colisão--\\
                =============================

            
                bodyTemp = (*itJog)->getBody();
                bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), 0));

                if (ChecarColisao(bodyTemp, (*itJogColider)->getBody())) {
                    bodyTemp = (*itJog)->getBody();
                    bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));

                    while (!ChecarColisao(bodyTemp, (*itJogColider)->getBody())) {
                        (*itJog)->getBodyPtr()->move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));

                        bodyTemp = (*itJog)->getBody();
                        bodyTemp.move(sf::Vector2f(NumeroMinimo((*itJog)->getHspd()), 0));
                    }

                    (*itJog)->setHspd(0);
                }

                bodyTemp = (*itJog)->getBody();
                bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), (*itJog)->getVspd()));

                if (ChecarColisao(bodyTemp, (*itJogColider)->getBody())) {
                    bodyTemp = (*itJog)->getBody();
                    bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), NumeroMinimo((*itJog)->getVspd())));

                    while (!ChecarColisao(bodyTemp, (*itJogColider)->getBody())) {
                        (*itJog)->getBodyPtr()->move(sf::Vector2f(0, NumeroMinimo((*itJog)->getVspd())));

                        bodyTemp = (*itJog)->getBody();
                        bodyTemp.move(sf::Vector2f((*itJog)->getHspd(), NumeroMinimo((*itJog)->getVspd())));
                    }

                    (*itJog)->setVspd(0);
                }
            }
        }


        (*itJog)->setSobAtrito(false);

        //--itera sobre todas plataformas--\\
        =====================================
        for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {

            //--percepção do jogador no chão--\\
            ===================================

            bodyTemp = (*itJog)->getBody();
            bodyTemp.move(sf::Vector2f(0, 1));

           if (ChecarColisao(bodyTemp, (*it)->getBody())) {
                (*itJog)->setNoChao(true);

                if (!(*itJog)->getSobAtrito()) {
                    (*it)->Obstacular((*itJog));
                    
                }
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

        
        //--itera sobre todos os obstaculos--\\
        ======================================
        for (std::list<Obstaculo*>::iterator it = listaObstaculos->begin(); it != listaObstaculos->end(); ++it) {

            if (ChecarColisao((*itJog)->getBody(), (*it)->getBody())) {
                ObstaculoDano* obstaculo1 = dynamic_cast<ObstaculoDano*>(*it);
                ObstaculoTeleporte* obstaculo2 = dynamic_cast<ObstaculoTeleporte*>(*it);

                if (obstaculo1) {
                    
                    obstaculo1->Obstacular(*itJog);
					int dir = NumeroMinimo((*itJog)->getBody().getPosition().x - (*it)->getBody().getPosition().x);
                    danoJogador(*itJog, dir);
					
                }

                if (obstaculo2) {
                    obstaculo2->Obstacular(*itJog);
                }
            
            }
		}


        (*itJog)->getBodyPtr()->move(sf::Vector2f((*itJog)->getHspd(), (*itJog)->getVspd()));

        if ((*itJog)->getVoador()) {
            (*itJog)->setNoChao(true);
        }
    }

    //--itera sobre cada inimigo--\\
   ================================
    for (std::vector<Inimigo*>::iterator itIni = listaInimigos->begin(); itIni != listaInimigos->end(); ++itIni) {

        sf::RectangleShape bodyTemp;


        //==interação inimigo e jogador===========================================================================================================================================

        for (Lista<Jogador*>::iterator itJog = listaJogador->begin(); itJog != listaJogador->end(); ++itJog) {

            for (Lista<Projetil*>::iterator itProjI = (*itIni)->getListaProjetil()->begin(); itProjI != (*itIni)->getListaProjetil()->end(); ++itProjI) {

                if (ChecarColisao((*itJog)->getBody(), (*itProjI)->getBody())) {

                    (*itProjI)->destruir();

                    if ((*itJog)->getState() == Jogador::Machucado) {
                        continue;
                    }

                    int direcao = NumeroMinimo((*itJog)->getBody().getPosition().x - (*itIni)->getBody().getPosition().x);

                    (*itJog)->operator--();
                    danoJogador((*itJog), direcao);
                    
                }
            }

            //==iteração sobre todos os tiros de cada jogador=====================================================================================================================
            for (Lista<Projetil*>::iterator itProjJ = (*itJog)->getListaProjetil()->begin(); itProjJ != (*itJog)->getListaProjetil()->end(); ++itProjJ) {
                
                
                
                if (ChecarColisao((*itIni)->getBody(), (*itProjJ)->getBody())) {
                    (*itProjJ)->destruir();

                    (*itIni)->operator--((*itProjJ)->getDano());
                }
                
                //==iteração sobre todas as plataformas===========================================================================================================================
                for(Lista<Plataforma*>::iterator itPlat = listaPlataforma->begin(); itPlat != listaPlataforma->end(); ++itPlat) {
					if (ChecarColisao((*itProjJ)->getBody(), (*itPlat)->getBody())) {
						(*itProjJ)->destruir();
					}
				}
            }


            if ((*itJog)->getState() == Jogador::Machucado) {
                continue;
            }

            bodyTemp = (*itIni)->getBody();
            bodyTemp.move(sf::Vector2f((*itIni)->getHspd(), (*itIni)->getVspd()));

            if (ChecarColisao(bodyTemp, (*itJog)->getBody())) {

                float dirX = NumeroMinimo((*itJog)->getBody().getPosition().x - (*itIni)->getBody().getPosition().x);
                (*itIni)->danificar((*itJog));
                danoJogador(*itJog, dirX);

            }
        }
    
     
    //==interação inimigo e plataforma========================================================================================================================================
     
        //--seta por padrão que o inimigo não está no chão e o proximo passo no chao--\\
        ================================================================================
        (*itIni)->setNoChao(false);
        bool invertFlag = true;
        bool invertFlagY = true;
        ZumbiFriorento* inimigo1 = dynamic_cast<ZumbiFriorento*>(*itIni);
        Zumbinana* inimigo2 = dynamic_cast<Zumbinana*>(*itIni);

        //--itera sobre todas plataformas--\\
        =====================================
        for (Lista<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {


            //--inverte a direção do inimigo--\\
            ====================================
            if (inimigo1 || inimigo2) {
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

        if (invertFlag) {
            if(inimigo1)
                inimigo1->invertDirectionX();
            else if(inimigo2)
                inimigo2->invertDirectionX();
        }

        (*itIni)->getBodyPtr()->move(sf::Vector2f((*itIni)->getHspd(), (*itIni)->getVspd()));

    //=========================================================================================================================================================================

    }
}

void GerenciadorDeColisoes::danoJogador(Jogador* jogador, int dirX)
{
    
    jogador->setState(Jogador::Machucado);

    jogador->setVspd(-8);
    jogador->setHspd(dirX * 6);
}

