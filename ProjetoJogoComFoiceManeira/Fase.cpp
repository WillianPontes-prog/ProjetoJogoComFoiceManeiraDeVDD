#include "Fase.h"

Fase::Fase():
	listaJogadores(new Lista<Jogador*>()),
	listaPlataformas(new Lista<Plataforma*>()),
	listaInimigos(new Lista<Inimigo*>()),
	listaObstaculos(new Lista<Obstaculo*>()),
	gerenciadorDeColisoes(new GerenciadorDeColisoes(this)),
	Ente()
{
	this->setGerenciadorGrafico();

    
	
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
    for(Lista<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todas as plataformas--\\
    =====================================
    for(Lista<Plataforma*>::iterator it = listaPlataformas->begin(); it != listaPlataformas->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todos os obst�culos--\\
    ====================================
    for(Lista<Obstaculo*>::iterator it = listaObstaculos->begin(); it != listaObstaculos->end(); it++)
    {
		(*it)->atualiza();
    }

    //--atualiza todos os inimigos--\\
    ==================================
    for(Lista<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); )
    {
        (*it)->atualiza();

        if ((*it)->getVida() <= 0) {
            Inimigo* projetil = *it;
            it = listaInimigos->removerElemento(it);
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
		throw std::runtime_error("N�o foi poss�vel abrir o arquivo JSON.");
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
    // Verifica se o n�mero de camadas solicitado est� dentro do alcance
    if (numLayers > mapa["layers"].size()) {
        throw std::runtime_error("N�mero de camadas fora do alcance.");
    }

    // Inicializa a matriz tridimensional
    vector<vector<vector<int>>> matriz3D;

    // Loop para cada camada
    for (int k = 0; k < numLayers; ++k) {
        auto camada = mapa["layers"][k];

        // Verifica se o tipo da camada � "tilelayer"
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

        // Adiciona a matriz da camada atual � matriz tridimensional
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
	Jogador* j = new Jogador(posX, posY, vida, new Arma(), j2);
	j->setGerenciadorGrafico();

	listaJogadores->adicionarElemento(j);
}

void Fase::criaPlataforma(float posX, float posY)
{
	Plataforma* p = new Plataforma(posX, posY);
	p->setGerenciadorGrafico();

	listaPlataformas->adicionarElemento(p);
}

void Fase::criarInimigo1(float posX, float posY, float vida)
{
	Inimigo1* i = new Inimigo1(listaJogadores, posX, posY, vida);
	i->setGerenciadorGrafico();

	listaInimigos->adicionarElemento(i);
}



