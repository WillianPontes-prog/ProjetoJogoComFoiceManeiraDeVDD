#include "ListaEntidade.h"
#include "Inimigo.h"

ListaEntidade::ListaEntidade():
listaEntidades(new Lista<Entidade*>())
{
}

ListaEntidade::~ListaEntidade()
{
}

void ListaEntidade::percorrer(GerenciadorDeColisoes* gdc)
{
	for (Lista<Entidade*>::iterator it = listaEntidades->begin();it!=listaEntidades->end(); )
	{
		(*it)->atualiza();

        Inimigo* ini = dynamic_cast<Inimigo*>(*it);

        if (ini) {
            if (ini->getVida() <= 0) {
                Inimigo* projetil = ini;
                it = listaEntidades->removerElemento(it);
                gdc->getListaInimigos()->removerElemento(projetil);
                delete projetil;
            }
            else {
                ++it;
            }
        }
        else {
            ++it;
        }
        


	}


}

void ListaEntidade::incluir(Entidade* entidade)
{
	listaEntidades->adicionarElemento(entidade);
}

json ListaEntidade::toJson()
{

    json j = json::array();

	for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
	{
        if ((*it)->toJson() != nullptr) {
            j.push_back((*it)->toJson());
        }
	}

    return j;
	
}
