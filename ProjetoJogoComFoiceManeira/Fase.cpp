#include "Fase.h"

Fase::Fase(bool Jogadores):
    Jogadores(Jogadores),
	
	gerenciadorDeColisoes(new GerenciadorDeColisoes(this)),
	Ente()
{
	this->setGerenciadorGrafico();

    Plataforma* Pdir = new Plataforma(-40, -320);
    Pdir->getBodyPtr()->setSize(sf::Vector2f(32, 1080));

    getListaPlataforma()->adicionarElemento(Pdir);

    Pdir = new Plataforma(968, -320);
    Pdir->getBodyPtr()->setSize(sf::Vector2f(32, 1080));

    getListaPlataforma()->adicionarElemento(Pdir);
	
}

Fase::~Fase()
{
}

void Fase::atualiza()
{
    
    atualizaSprite(0, -3);
    gerenciadorGrafico->draw(spriteFundo);
    draw();

    //--atualiza todos os jogadores--\\
    ===================================
    for(Lista<Jogador*>::iterator it = getListaJogadores()->begin(); it != getListaJogadores()->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todas as plataformas--\\
    =====================================
    for(Lista<Plataforma*>::iterator it = getListaPlataforma()->begin(); it != getListaPlataforma()->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todos os obstáculos--\\
    ====================================
    for(Lista<Obstaculo*>::iterator it = getListaObstaculos()->begin(); it != getListaObstaculos()->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todos os inimigos--\\
    ==================================
    for(Lista<Inimigo*>::iterator it = getListaInimigos()->begin(); it != getListaInimigos()->end(); )
    {
        (*it)->atualiza();

        if ((*it)->getVida() <= 0) {
            Inimigo* projetil = *it;
            it = getListaInimigos()->removerElemento(it);
            delete projetil;
        }
        else {
            ++it;
        }
    }

	gerenciadorDeColisoes->tratarColisoes();
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

void Fase::criaJogador(float posX, float posY, int vida, bool j2)
{
    Arma* arm; 
    bool voar = false;

    if (j2) {
        arm = new Arma(8, 1, 35, 12, sf::Color::Magenta, sf::Vector2f(8, 8));
        voar = true;
    }
	else {
		arm = new Arma(16, 2, 80, 15, sf::Color::Yellow, sf::Vector2f(15,8));
	}

	Jogador* j = new Jogador(posX, posY, vida, arm, j2, voar);
	j->setGerenciadorGrafico();

	getListaJogadores()->adicionarElemento(j);
}

void Fase::criaPlataforma(float posX, float posY)
{
	Plataforma* p = new Plataforma(posX, posY);
	p->setGerenciadorGrafico();

	getListaPlataforma()->adicionarElemento(p);
}

void Fase::criaFogo(float posX, float posY)
{
    ObstaculoDano* o = new ObstaculoDano(posX, posY, 1);
    o->setGerenciadorGrafico();

    getListaObstaculos()->adicionarElemento(o);
}



void Fase::criarInimigo2(float posX, float posY, float vida)
{   
    Arma* arma = new Arma(80,1,30,5,sf::Color::Red,sf::Vector2f(15,4));
    Inimigo2* i = new Inimigo2(getListaJogadores(), posX, posY, vida, arma);
    i->setGerenciadorGrafico();

    getListaInimigos()->adicionarElemento(i);
}


Lista<Jogador*>* Fase::getListaJogadores()      { return	gerenciadorDeColisoes->getListaJogadores(); }
Lista<Plataforma*>* Fase::getListaPlataforma()  { return	gerenciadorDeColisoes->getListaPlataforma(); }
Lista<Inimigo*>* Fase::getListaInimigos()       { return    gerenciadorDeColisoes->getListaInimigos(); }
Lista<Obstaculo*>* Fase::getListaObstaculos()   { return    gerenciadorDeColisoes->getListaObstaculos(); }


