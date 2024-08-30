#pragma once
#include "Fase.h"
#include "ObstaculoDano.h"
#include "ObstaculoTeleporte.h"
#include "Inimigo.h"
#include <vector>

namespace Fases {
	class Fase;
}
class MudarFase;

namespace Gerenciadores {
    class GerenciadorDeColisoes
    {
    private:
        Listas::Lista<Entidades::Personagens::Jogador*>* listaJogador;
        Listas::Lista<Entidades::Obstaculos::Plataforma*>* listaPlataforma;
        std::vector<Entidades::Personagens::Inimigo*>* listaInimigos;
        std::list<Entidades::Obstaculos::Obstaculo*>* listaObstaculos;

        MudarFase* mudarFase;

        Fases::Fase* fase;

    public:
        GerenciadorDeColisoes(Fases::Fase* fase);
        ~GerenciadorDeColisoes();

        void tratarColisoes();

        const int ChecarColisao(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
            sf::FloatRect bounds1 = rect1.getGlobalBounds();
            sf::FloatRect bounds2 = rect2.getGlobalBounds();
            return bounds1.intersects(bounds2);
        }

        int NumeroMinimo(const float valor)
        {
            if (valor == 0) { return 0; }
            else { return (valor / abs(valor)); }
        }

        void danoJogador(Entidades::Personagens::Jogador* jogador, int dirX);

        Listas::Lista<Entidades::Personagens::Jogador*>* getListaJogadores();
        Listas::Lista<Entidades::Obstaculos::Plataforma*>* getListaPlataforma();
        std::vector<Entidades::Personagens::Inimigo*>* getListaInimigos();
        std::list<Entidades::Obstaculos::Obstaculo*>* getListaObstaculos();

        MudarFase* getMudarFase() { return mudarFase; };
        void setMudarFase(MudarFase* m) { mudarFase = m; };

        void tratarColisaoJogObst();
        void tratarColisaoJogInim();
        void tratarColisaoJogJog();
        void tratarColisaoJogProjetil();
        void tratarColisaInimProj();
    };
}
