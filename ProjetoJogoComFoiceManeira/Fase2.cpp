#include "Fase2.h"

using namespace Fases;
using namespace Obstaculos;
using namespace Personagens;

void Fase2::carregarFase() {
    json j = lerArquivoJSON("save.json");

    auto outerArray = j.get<std::vector<std::vector<json>>>();

    for (const auto& innerArray : outerArray) {
        for (const auto& item : innerArray) {

            int classType = item.at(classe).get<int>();
            float posX = item.at(pX).get<float>();
            float posY = item.at(pY).get<float>();
            int vida = -1;
            int tamX = -1;
            int tamY = -1;
            int tempo = -1;
            int velocidade = -1;
            int dano = -1;
            int corR = -1;
            int corG = -1;
            int corB = -1;
            float direcaoX = -1;
            float direcaoY = -1;

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
            case Entidade::Tipo::_projetil:

                tamX = item.at(TAM_X).get<int>();
                tamY = item.at(TAM_Y).get<int>();
                tempo = item.at(TEMPO).get<int>();
                velocidade = item.at(VELOCIDADE).get<int>();
                dano = item.at(DANO).get<int>();
                corR = item.at(COR_R).get<int>();
                corG = item.at(COR_G).get<int>();
                corB = item.at(COR_B).get<int>();
                direcaoX = item.at(DIRECAO_X).get<float>();
                direcaoY = item.at(DIRECAO_Y).get<float>();


                carregarProjeteis(posX, posY, tamX, tamY, tempo, velocidade, dano, sf::Color(corR, corG, corB), sf::Vector2f(direcaoX, direcaoY));

                break;
            default:

                break;
            }
        }

    }
}

Fase2::Fase2(bool Jogadores, Jogo* jg, bool carregar) :
    Fase(Jogadores, jg, carregar),
    numFogo{ 0, 3, 5, 0 },
    numZumbiDragao{ 0, 3, 4, 0 }
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
		criarChefao(posX, posY, 10);
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
    case 2509: //plataforma aleatoria
        if (comPlataforma) {
            criarPlataforma(posX, posY, true);
        }
		break;
    default:

        break;
    }
}

void Fase2::criarChefao(float posX, float posY, int vida)
{
    int chance = rand() % 2;

    if (numZumbiDragao[2] - numZumbiDragao[3] <= numZumbiDragao[1]) {
        chance = 1;
    }


    if (numZumbiDragao[0] > numZumbiDragao[2]) {
        chance = 0;
    }

    if (continunando) {
        chance = 1;
    }

    if (chance) {
        BuilderArma b = BuilderArma();
        b.buildArmaChefe();
        b.buildVermelho();
        Arma* arma = b.getArma();
        ZumbiDragao* chefao = new ZumbiDragao(getListaJogadores(), posX, posY, vida, 1000, arma);
        chefao->setGerenciadorGrafico();

        sf::Vector2f pos = sf::Vector2f(25 * 32, 13 * 32);

        switch (numZumbiDragao[0])
        {
        case 1:
            pos = sf::Vector2f(15 * 32, 5 * 32);

            break;
        case 2:
            pos = sf::Vector2f(11 * 32, 9 * 32);

            break;
        case 3:
            pos = sf::Vector2f(5 * 32, 3 * 32);

            break;
        default:
            break;
        }
        


        chefao->setPosicao2(pos);
        listaEntidades->incluir(chefao);
        getListaInimigos()->push_back(chefao);

        numZumbiDragao[0]++;
    }
    numZumbiDragao[3]++;
    
}

void Fase2::criarFogo(float posX, float posY)
{
    int chance = rand() % 2;

    if (numFogo[2] - numFogo[3] <= numFogo[1]) {
        chance = 1;
    }


    if (numFogo[0] > numFogo[2]) {
        chance = 0;
    }

    if (continunando) {
        chance = 1;
    }

    if (chance) {
        ObstaculoDano* o = new ObstaculoDano(posX, posY, 1);
        o->setGerenciadorGrafico();

        listaEntidades->incluir(o);
        getListaObstaculos()->push_back(o);

        numFogo[0]++;
    }
    numFogo[3]++;
    
    
}

bool Fase2::checarMudarFase()
{
    if (getListaInimigos()->size() == 0)
        return true;


    return false;
}

