#include "ListaEntidade.h"
#include "Entidades/Personagens/Inimigo.h"

using namespace Gerenciadores;
using namespace Entidades::Personagens;

namespace Listas{

    ListaEntidade::ListaEntidade():
    listaEntidades(new Lista<Entidades::Entidade*>()),
    pontosPorPasso(0)
    {

    }

    ListaEntidade::~ListaEntidade()
    {
        for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
	    {
		    delete *it;
	    }
	    delete listaEntidades;
    }

    void ListaEntidade::percorrer(Gerenciadores::GerenciadorDeColisoes* gdc)
    {
        pontosPorPasso = 0;

    
	    for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin();it!=listaEntidades->end(); )
	    {
		    (*it)->atualiza();

            Inimigo* ini = dynamic_cast<Inimigo*>(*it);

            if (ini) {
                if (ini->getVida() <= 0) {
                    Inimigo* inimigo = ini;
                    it = listaEntidades->removerElemento(it);


                    auto it = std::find(gdc->getListaInimigos()->begin(), gdc->getListaInimigos()->end(), inimigo);
                    if (it != gdc->getListaInimigos()->end()) {
                        gdc->getListaInimigos()->erase(it);
                    }

                

                    pontosPorPasso++;

                    delete inimigo;
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

    void ListaEntidade::incluir(Entidades::Entidade* entidade)
    {
	    listaEntidades->adicionarElemento(entidade);
    }

    json ListaEntidade::toJson()
    {

        json j = json::array();

	    for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
	    {
            if ((*it)->toJson() != nullptr) {

            

                j.push_back((*it)->toJson());

                EntidadeColidivel* ec = dynamic_cast<EntidadeColidivel*>(*it);
                if (ec) {
                    for (auto it = ec->getListaProjetil()->begin(); it != ec->getListaProjetil()->end(); it++)
                    {
                        j.push_back((*it)->toJson());
                    }
                }
            }
	    }

        return j;
	
    }

}