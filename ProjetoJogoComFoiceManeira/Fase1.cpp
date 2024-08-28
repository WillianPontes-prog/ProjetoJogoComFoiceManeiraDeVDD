#include "Fase1.h"

void Fase1::carregarFase()
{
    json j = lerArquivoJSON("save.json");

    auto outerArray = j.get<std::vector<std::vector<json>>>();

    for (const auto& innerArray : outerArray) {
        for (const auto& item : innerArray) {

            int classType = item.at("classe").get<int>();
            float posX = item.at("posX").get<float>();
            float posY = item.at("posY").get<float>();
            int vida = -1;

            switch (classType)
            {

            case Entidade::Tipo::_jogador:
                vida = item.at("Vida").get<int>();
                criarJogador(posX, posY, vida, false);

                break;
            case Entidade::Tipo::_jogador2:
                vida = item.at("Vida").get<int>();
                criarJogador(posX, posY, vida, true);

                break;
            case Entidade::Tipo::_plataforma:
                criarPlataforma(posX, posY);

                break;
            case Entidade::Tipo::_zumbifriorento:
                vida = item.at("Vida").get<int>();
                criarZumbiFriorento(posX, posY, vida);

                break;
            case Entidade::Tipo::_zumbinana:
                vida = item.at("Vida").get<int>();
                criarZumbinana(posX, posY, vida);


                break;
            default:

                break;
            }
        }

    }
}

Fase1::Fase1(bool Jogadores, Jogo* jg, bool carregar):
	Fase(Jogadores, jg, carregar),
    numZumbiFriorento{0, 3, 5, 0}
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
    default:

    break;
    }
}

void Fase1::criarTeleporte(float posX, float posY)
{
    ObstaculoTeleporte* o = new ObstaculoTeleporte(sf::Vector2f(posX, posY));
    o->setGerenciadorGrafico();

    listaEntidades->incluir(o);
    getListaObstaculos()->adicionarElemento(o);
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

    if (chance) {
        ZumbiFriorento* i = new ZumbiFriorento(getListaJogadores(), posX, posY, vida);
        i->setGerenciadorGrafico();

        listaEntidades->incluir(i);
        getListaInimigos()->adicionarElemento(i);

        numZumbiFriorento[0]++;
    }

    numZumbiFriorento[3]++;
}