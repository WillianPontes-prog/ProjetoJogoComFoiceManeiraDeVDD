#pragma once
#include"Lista.h"
#include"Entidade.h"
#include"GerenciadorDeColisoes.h"

class GerenciadorDeColisoes;

class ListaEntidade {
private:
    Lista<Entidade*>* listaEntidades;

public:
    ListaEntidade();
	~ListaEntidade();
    void percorrer(GerenciadorDeColisoes* gc);
	void incluir(Entidade* entidade);


};