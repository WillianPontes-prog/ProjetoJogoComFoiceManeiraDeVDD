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
        Listas::Lista<Personagens::Jogador*>* listaJogador;
        Listas::Lista<Obstaculos::Plataforma*>* listaPlataforma;
        std::vector<Personagens::Inimigo*>* listaInimigos;
        std::list<Obstaculos::Obstaculo*>* listaObstaculos;

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

        void danoJogador(Personagens::Jogador* jogador, int dirX);

        Listas::Lista<Personagens::Jogador*>* getListaJogadores();
        Listas::Lista<Obstaculos::Plataforma*>* getListaPlataforma();
        std::vector<Personagens::Inimigo*>* getListaInimigos();
        std::list<Obstaculos::Obstaculo*>* getListaObstaculos();

        MudarFase* getMudarFase() { return mudarFase; };
        void setMudarFase(MudarFase* m) { mudarFase = m; };

        void tratarColisaoJogObst();
        void tratarColisaoJogInim();
        void tratarColisaoJogJog();
        void tratarColisaoJogProjetil();
        void tratarColisaInimProj();
    };
}
