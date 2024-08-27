#pragma once
#include"Lista.h"
#include"Entidade.h"

class ListaEntidade {
private:
    Lista<Entidade*>* listaEntidades;

public:
    ListaEntidade();
	~ListaEntidade();
    void percorrer();
	void incluir(Entidade* entidade);


};