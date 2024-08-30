#include "Fase2.h"

void Fase2::carregarFase() {
    json j = lerArquivoJSON("save.json");

    auto outerArray = j.get<std::vector<std::vector<json>>>();

    for (const auto& innerArray : outerArray) {
        for (const auto& item : innerArray) {

            int classType = item.at(classe).get<int>();
            float posX = item.at(pX).get<float>();
            float posY = item.at(pY).get<float>();
            int vida = -1;

            switch (classType)
            {

            case Entidade::Tipo::_jogador:
                vida = item.at(vd).get<int>();
                criarJogador(posX, posY, vida, false);

                break;
            case Entidade::Tipo::_jogador2:
                vida = item.at(vd).get<int>();
                criarJogador(posX, posY, vida, true);

                break;
            case Entidade::Tipo::_plataforma:
                criarPlataforma(posX, posY);

                break;
            case Entidade::Tipo::_zumbidragao:
                vida = item.at(vd).get<int>();
                criarChefao(posX, posY, vida);

                break;
            case Entidade::Tipo::_zumbinana:
                vida = item.at(vd).get<int>();
                criarZumbinana(posX, posY, vida);

                break;
            case Entidade::Tipo::_obstaculoDano:
                criarFogo(posX, posY);

                break;
            case Entidade::Tipo::_alternadorDeFase:
                criarMudarFase(posX, posY);

                break;
            default:

                break;
            }
        }

    }
}

Fase2::Fase2(bool Jogadores, Jogo* jg, bool carregar) :
    Fase(Jogadores, jg, carregar),
    nChefao(0)
{
    setGerenciadorGrafico();

    if (!carregar)
        gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaF2.json"), 3));
    else
        carregarFase();
}

Fase2::~Fase2()
{
}

void Fase2::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2527:  //Jogador
        criarJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if (Jogadores)
            criarJogador(posX, posY, 5, true);
        break;
    case 2520:  //chefao
		criarChefao(posX, posY, 20);
		break;
    case 2505:  //Plataforma
        criarPlataforma(posX, posY);
        break;
    case 2522:  //Inimigo2
        criarZumbinana(posX, posY);
        break;
    case 2511: //Fogo
        criarFogo(posX, posY);
        break;
    default:

        break;
    }
}

void Fase2::criarChefao(float posX, float posY, int vida)
{
    ZumbiDragao* chefao = new ZumbiDragao(getListaJogadores(), posX, posY, vida, 600, new Arma(90,1, 90, 10,sf::Color::Green,sf::Vector2f(20,10)));
    chefao->setGerenciadorGrafico();

    sf::Vector2f pos = sf::Vector2f(25*32, 13*32);

    if(nChefao == 1){
        pos = sf::Vector2f(15*32, 5*32);
    }

    chefao->setPosicao2(pos);
	listaEntidades->incluir(chefao);
	getListaInimigos()->push_back(chefao);

    nChefao++;
}

void Fase2::criarFogo(float posX, float posY)
{
    ObstaculoDano* o = new ObstaculoDano(posX, posY, 1);
    o->setGerenciadorGrafico();

    listaEntidades->incluir(o);
    getListaObstaculos()->push_back(o);
}

bool Fase2::checarMudarFase()
{
    if (getListaInimigos()->size() == 0)
        return true;


    return false;
}

