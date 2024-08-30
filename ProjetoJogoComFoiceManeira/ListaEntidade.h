#pragma once
#include"Lista.h"
#include"Entidade.h"
#include"GerenciadorDeColisoes.h"

class GerenciadorDeColisoes;

class ListaEntidade {
private:
    Lista<Entidade*>* listaEntidades;
    int pontosPorPasso;

public:
    ListaEntidade();
	~ListaEntidade();
    void percorrer(GerenciadorDeColisoes* gc);
	void incluir(Entidade* entidade);

    json toJson();

    int getPontosPorPasso() { return pontosPorPasso; }
};

