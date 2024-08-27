#include "ListaEntidade.h"

ListaEntidade::ListaEntidade():
listaEntidades(new Lista<Entidade*>())
{
}

ListaEntidade::~ListaEntidade()
{
}

void ListaEntidade::percorrer()
{
	for (Lista<Entidade*>::iterator it = listaEntidades->begin();it!=listaEntidades->end();it++)
	{
		(*it)->atualiza();
	}
}

void ListaEntidade::incluir(Entidade* entidade)
{
	listaEntidades->adicionarElemento(entidade);
}


