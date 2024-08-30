#include "Fase1.h"

void Fase1::carregarFase()
{
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
            case Entidade::Tipo::_zumbifriorento:
                vida = item.at(vd).get<int>();
                criarZumbiFriorento(posX, posY, vida);

                break;
            case Entidade::Tipo::_zumbinana:
                vida = item.at(vd).get<int>();
                criarZumbinana(posX, posY, vida);

                break;
            case Entidade::Tipo::_obstaculoTeleporte:
                criarTeleporte(posX, posY);

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

Fase1::Fase1(bool Jogadores, Jogo* jg, bool carregar):
	Fase(Jogadores, jg, carregar),
    numZumbiFriorento{0, 3, 5, 0},
    numTeleporte{0, 3, 6, 0}
    
{
    setGerenciadorGrafico();

    if(!carregar)
        gerarFase(extrairCamadas(lerArquivoJSON("tileds/MapaF1.json"), 2));
    else
        carregarFase();
}

Fase1::~Fase1()
{
}

void Fase1::criaEntidades(float posX, float posY, int n)
{
    switch (n)
    {
    case 2527:  //Jogador
        criarJogador(posX, posY, 5);
        break;
    case 2525:  //Jogador 2
        if(Jogadores)
            criarJogador(posX, posY, 5, true);
        break;
    case 2520:  //Inimigo1
        
		criarZumbiFriorento(posX, posY);
		break;
    case 2505:  //Plataforma
        criarPlataforma(posX, posY);
        break;
    case 2511:  //tp
		criarTeleporte(posX, posY);
        break;
    case 2522:  //Inimigo2
		criarZumbinana(posX, posY);
		break;
    case 2536:
        criarMudarFase(posX, posY);
        break;
    case 2509: //plataforma aleatoria
        if (comPlataforma) {
            criarPlataforma(posX, posY, true);
        }
    default:

    break;
    }
}

void Fase1::criarTeleporte(float posX, float posY)
{

    int chance = rand() % 2;

    if (numTeleporte[2] - numTeleporte[3] <= numTeleporte[1]) {
        chance = 1;
    }


    if (numTeleporte[0] > numTeleporte[2]) {
        chance = 0;
    }

    if (continunando) {
        chance = 1;
    }

    if (chance) {
        ObstaculoTeleporte* o = new ObstaculoTeleporte(sf::Vector2f(posX, posY));
        o->setGerenciadorGrafico();

        listaEntidades->incluir(o);
        getListaObstaculos()->push_back(o);

        numTeleporte[0]++;
    }

    numTeleporte[3]++;
    
}

void Fase1::criarZumbiFriorento(float posX, float posY, float vida)
{

    int chance = rand() % 2;

    if(numZumbiFriorento[2] - numZumbiFriorento[3] <= numZumbiFriorento[1]){
        chance = 1;
	}
    

    if (numZumbiFriorento[0] > numZumbiFriorento[2]) {
        chance = 0;
    }

    if (continunando) {
        chance = 1;
    }

    if (chance) {
        ZumbiFriorento* i = new ZumbiFriorento(getListaJogadores(), posX, posY, vida);
        i->setGerenciadorGrafico();

        listaEntidades->incluir(i);
        getListaInimigos()->push_back(i);

        numZumbiFriorento[0]++;
    }

    numZumbiFriorento[3]++;
}