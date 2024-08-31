#include "Fase.h"
#include "../Jogo.h"
#include "../GerenciadorDeColisoes.h"

using namespace Listas;
using namespace Gerenciadores;
using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

namespace Fases {

    Fase::Fase(bool Jogadores, Jogo* jg, bool continuar) :
        Jogadores(Jogadores),
        listaEntidades(new ListaEntidade()),
        gerenciadorDeColisoes(new Gerenciadores::GerenciadorDeColisoes(this)),
        jg(jg),
        continunando(continuar),
        Ente(),
        numZumbinana{ 0, 3, 4, 0 }
    {
        comPlataforma = (rand() % 2);

        this->setGerenciadorGrafico();

        if (!continunando) {
            Plataforma* Pdir = new Plataforma(-40, -320);
            Pdir->getBodyPtr()->setSize(sf::Vector2f(32, 1080));

            getListaPlataforma()->adicionarElemento(Pdir);

            Pdir = new Plataforma(968, -320);
            Pdir->getBodyPtr()->setSize(sf::Vector2f(32, 1080));

            getListaPlataforma()->adicionarElemento(Pdir);
        }


    }

    Fase::~Fase()
    {
        delete listaEntidades;
        delete gerenciadorDeColisoes;
    }

    void Fase::atualiza()
    {

        atualizaSprite(0, 0);
        gerenciadorGrafico->draw(spriteFundo);
        draw();

        listaEntidades->percorrer(gerenciadorDeColisoes);
        gerenciadorDeColisoes->tratarColisoes();

        int ppp = listaEntidades->getPontosPorPasso();

        for (int p = 0; p < ppp; p++) {
            jg->operator++();
        }

        bool f = false;

        for (Lista<Jogador*>::iterator it = getListaJogadores()->begin(); it != getListaJogadores()->end(); it++)
        {
            if ((*it)->getVida() > 0)
            {
                f = true;
            }
        }

        if (!f) {
            jg->setarModoDeJogo(Jogo::modos::_fimDeJogo);
        }
    }

    json Fase::lerArquivoJSON(const std::string caminho) {
        std::ifstream arquivo(caminho);
        if (!arquivo.is_open()) {
            throw std::runtime_error("Não foi possível abrir o arquivo JSON.");
        }
        json j;
        arquivo >> j;
        return j;
    }

    void Fase::gerarFase(vector<vector<vector<int>>> mapa)
    {
        // Loop para cada camada
        for (int k = 0; k < mapa.size(); ++k) {
            auto camada = mapa[k];

            // Loop para cada linha da camada
            for (int i = 0; i < camada.size(); ++i) {
                // Loop para cada coluna da camada
                for (int j = 0; j < camada[i].size(); ++j) {

                    criaEntidades(j * 32, i * 32, camada[i][j]);
                }
            }
        }
    }

    vector<vector<vector<int>>> Fase::extrairCamadas(const json& mapa, int numLayers) {
        // Verifica se o número de camadas solicitado está dentro do alcance
        if (numLayers > mapa["layers"].size()) {
            throw std::runtime_error("Número de camadas fora do alcance.");
        }

        // Inicializa a matriz tridimensional
        vector<vector<vector<int>>> matriz3D;

        // Loop para cada camada
        for (int k = 0; k < numLayers; ++k) {
            auto camada = mapa["layers"][k];

            // Verifica se o tipo da camada é "tilelayer"
            if (camada["type"] != "tilelayer") {
                throw std::runtime_error("Tipo de camada incorreto.");
            }

            int largura = camada["width"];
            int altura = camada["height"];
            auto dados = camada["data"];

            // Inicializa a matriz bidimensional para a camada atual
            vector<vector<int>> matriz(altura, vector<int>(largura, 0));

            // Preenche a matriz bidimensional com os dados da camada
            for (int i = 0; i < altura; ++i) {
                for (int j = 0; j < largura; ++j) {
                    matriz[i][j] = dados[i * largura + j];
                }
            }

            // Adiciona a matriz da camada atual à matriz tridimensional
            matriz3D.push_back(matriz);
        }

        return matriz3D;
    }

    void Fase::setSpriteFundo(sf::Texture* texture)
    {
        texturaFundo = texture;
        if (texturaFundo != NULL) {
            spriteFundo.setTexture(*texturaFundo);
            spriteFundo.setPosition(0, 0);
        }
    }

    void Fase::salvarFase()
    {
        json j = json::array();

        j.push_back(listaEntidades->toJson());

        std::ofstream outputFile("save.json");
        if (!outputFile.is_open()) {
            std::cerr << "Erro ao abrir o arquivo JSON para escrita!" << std::endl;
        }
        else {

            outputFile << j.dump(4); // Salvando com identação de 4 espaços
            outputFile.close();
        }


    }

    void Fase::criarJogador(float posX, float posY, int vida, bool j2)
    {
        Arma* arm;
        bool voar = false;
        BuilderArma b = BuilderArma();

        if (j2) {
            b.buildArmaJogador2();
            b.buildRoxo();
            arm = b.getArma();
            voar = true;
        }
        else {
            b.buildArmaJogador1();
            b.buildAzul();
            arm = b.getArma();
        }


        Jogador* j = new Jogador(posX, posY, vida, arm, j2, voar);
        jg->adicionarObserver(j);
        j->setGerenciadorGrafico();

        listaEntidades->incluir(j);
        getListaJogadores()->adicionarElemento(j);
    }

    void Fase::criarPlataforma(float posX, float posY, bool aleatoria)
    {
        Plataforma* p = new Plataforma(posX, posY, aleatoria);
        p->setGerenciadorGrafico();

        listaEntidades->incluir(p);
        getListaPlataforma()->adicionarElemento(p);
    }

    void Fase::criarMudarFase(float posX, float posY)
    {
        MudarFase* m = new MudarFase(posX, posY, 32, 32, jg);
        m->setGerenciadorGrafico();

        listaEntidades->incluir(m);
        setMudarFase(m);
    }

    void Fase::criarZumbinana(float posX, float posY, float vida)
    {

        int chance = rand() % 2;

        if (numZumbinana[2] - numZumbinana[3] <= numZumbinana[1]) {
            chance = 1;
        }


        if (numZumbinana[0] > numZumbinana[2]) {
            chance = 0;
        }

        if (continunando) {
            chance = 1;
        }

        if (chance) {

            BuilderArma b = BuilderArma();
            b.buildArmaZumbinana();
            b.buildAmarelo();
            Arma* arma = b.getArma();

            Zumbinana* i = new Zumbinana(getListaJogadores(), posX, posY, vida, arma);
            i->setGerenciadorGrafico();

            listaEntidades->incluir(i);
            getListaInimigos()->push_back(i);

            numZumbinana[0]++;
        }

        numZumbinana[3]++;
    }

    void Fase::carregarProjeteis(float posX, float posY, float tamX, float tamY, int tempo, int velocidade, int dano, sf::Color cor, sf::Vector2f dir)
    {
        Entidades::Projetil* p = new Entidades::Projetil(posX, posY, tamX, tamY, tempo, velocidade, dano, cor, dir);
        p->setGerenciadorGrafico();

        listaEntidades->incluir(p);

    }

    Lista<Jogador*>* Fase::getListaJogadores() { return	gerenciadorDeColisoes->getListaJogadores(); }
    Lista<Plataforma*>* Fase::getListaPlataforma() { return	gerenciadorDeColisoes->getListaPlataforma(); }
    std::vector<Inimigo*>* Fase::getListaInimigos() { return    gerenciadorDeColisoes->getListaInimigos(); }
    std::list<Obstaculo*>* Fase::getListaObstaculos() { return    gerenciadorDeColisoes->getListaObstaculos(); }

    MudarFase* Fase::getMudarFase()
    {
        return gerenciadorDeColisoes->getMudarFase();
    }

    void Fase::setMudarFase(MudarFase* m)
    {
        gerenciadorDeColisoes->setMudarFase(m);
    }

}
