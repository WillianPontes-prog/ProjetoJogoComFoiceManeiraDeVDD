        #pragma once
#include "Entidade.h"
#include "Arma.h"


namespace Entidades {
    namespace Personagens {
        class EntidadeColidivel : public Entidade {
        protected:

            Listas::Lista<Projetil*>* listaProjetil;
            Arma* arma;

            float velocidade;

            float hspd;
            float vspd;

            int vida;

            bool noChao;

            int tempoRecarregando;

            sf::Vector2f direcao;

            int maxTempoMachucado;
            int tempoMachucado;

            bool sobAtrito;

        public:
            EntidadeColidivel(int posX = 0, int posY = 0, int vida = 5, Arma* arma = NULL);
            ~EntidadeColidivel();

            void setVelocidade(const float velocidade) { this->velocidade = velocidade; };

            virtual void move() = 0;
            virtual void atualiza() = 0;

            const float getHspd() { return hspd; };
            const float getVspd() { return vspd; };

            void setHspd(const float hspd) { this->hspd = hspd; };
            void setVspd(const float vspd) { this->vspd = vspd; };

            void setNoChao(bool noChao) { this->noChao = noChao; };

            void drawVida(float posX, float poY, sf::Sprite sprVida);

            virtual void operator--() { vida--; };

            void disparar();

            void atualizaProjetil();

            virtual void sacarArma() = 0;

            Listas::Lista<Projetil*>* getListaProjetil();

            void setArma(Arma* arma) { this->arma = arma; };
            Arma* getArma() { return arma; };

            const int getVida() { return vida; }

            void    setSobAtrito(const bool sobAtrito) { this->sobAtrito = sobAtrito; };
            const float   getSobAtrito() { return sobAtrito; };
        };
    }
}