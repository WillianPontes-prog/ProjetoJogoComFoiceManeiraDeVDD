#include "EntidadeColisao.h"


EntidadeColisao::EntidadeColisao(float dimX, float dimY, float posX, float posY):
	Entidade(dimX, dimY,posX, posY),
	listaAtaques(new Lista<Ataque*>())
{

}




EntidadeColisao::~EntidadeColisao()
{
}
