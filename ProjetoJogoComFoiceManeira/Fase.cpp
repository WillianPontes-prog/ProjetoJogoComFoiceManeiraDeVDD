#include "Fase.h"

void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	levelGenerate();

}

Fase::Fase(sf::RenderWindow* window, std::string jsonFile):
entityGenerator(new EntityGenerator(this))
{

	this->window = window;
	this->jsonFile = jsonFile;

	listaPlataforma		= new std::list<Plataforma*>();
	listaJogadores		= new std::list<Jogador*>();
	listaInimigos		= new std::list<Inimigo*>();


	inicializaElementos();
}

Fase::~Fase()
{
}

void Fase::levelGenerate()
{

	//--------gerando entidades e descobrindo qual é--------\\
	==========================================================
	json mapa = lerArquivoJSON(jsonFile);

	// Extrair e imprimir a matriz
	vector<vector<vector<int>>> matriz = extrairCamadas(mapa,2);
	Entidade* entidade = nullptr;

	for(int i = 0; i < matriz.size(); i++){
		for(int j = 0; j < matriz[i].size(); j++){
			for (int k = 0; k < matriz[i][j].size(); k++) {
				entityGenerator->execute(k * 32,  j* 32, matriz[i][j][k]);
			}
		}
	}




	//--------entregando elementos genericos para cada entidade--------\\
	=====================================================================

	//plataformas
	for (std::list<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {
		(*it)->set_Window(window);
	}

	//inimigos
	for (std::list<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); ++it) {
		(*it)->set_Window(window);
		(*it)->set_listPlat(listaPlataforma);
		(*it)->set_listJogador(listaJogadores);
	}

	//Players
	for (std::list<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {
		(*it)->set_Window(window);
		(*it)->set_listPlat(listaPlataforma);
	}
}

void Fase::atualiza()
{
	sf::Texture texture;
	if (!texture.loadFromFile("Fase_1.png"))
	{
		std::cerr << "Erro ao carregar a imagem!" << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window->draw(sprite);


	//desenha todas entidades
	for (std::list<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {

		(*it)->atualiza();
	}


	for (std::list<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {

		(*it)->atualiza();
	}


	for (std::list<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); ++it) {

		(*it)->atualiza();
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
