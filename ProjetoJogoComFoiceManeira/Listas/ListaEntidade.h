#pragma once
#include"Lista.h"
#include"Entidades/Entidade.h"
#include"Gerenciadores/GerenciadorDeColisoes.h"

namespace Gerenciadores { class GerenciadorDeColisoes; }

namespace Listas {
    class ListaEntidade {
    private:
        Lista<Entidades::Entidade*>* listaEntidades;
        int pontosPorPasso;

    public:
        ListaEntidade();
        ~ListaEntidade();
        void percorrer(Gerenciadores::GerenciadorDeColisoes* gc);
        void incluir(Entidades::Entidade* entidade);

        json toJson();

        int getPontosPorPasso() { return pontosPorPasso; }
    };
}
