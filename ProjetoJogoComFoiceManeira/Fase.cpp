#include "Fase.h"


void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	gerarFase();

}

Fase::Fase(std::string jsonFile):
listaPlataforma (new Lista<Plataforma*>()),
listaJogadores(new Lista<Jogador*>()),
listaInimigos(new Lista<Inimigo*>()),
gerenciadorColisao(new GerenciadorDeColisao(this))
{
	this->caminhoJson = jsonFile;

	inicializaElementos();
}

Fase::~Fase()
{
}

Jogador* Fase::criarJogador(float posX, float posY)
{
	Jogador* jogador = new Jogador(32, 32, posX, posY);

	return jogador;
}

Inimigo* Fase::criarInimigo(float posX, float posY)
{
	Inimigo* inimigo = new Inimigo(32, 32, posX, posY);

	return inimigo;
}

Plataforma* Fase::criarPlataforma(float posX, float posY)
{
	Plataforma* plataforma = new Plataforma(32, 32, posX, posY);

	return plataforma;
}

void Fase::gerarFase()
{
	//-----------------gerando entidades-----------------\\
	=======================================================
	json mapa = lerArquivoJSON(caminhoJson);

	// Extrair e imprimir a matriz
	vector<vector<vector<int>>> matriz = extrairCamadas(mapa,2);
	Entidade* entidade = nullptr;

	for(int i = 0; i < matriz.size(); i++){
		for(int j = 0; j < matriz[i].size(); j++){
			for (int k = 0; k < matriz[i][j].size(); k++) {

				int n = matriz[i][j][k];
				float posX = j * 32;
				float posY = i * 32;

				switch (n)
				{
				case 1313:
					get_listaJogadores()->adicionarElemento(criarJogador(posX, posY));
					break;
				case 1337:
					get_listaInimigos()->adicionarElemento(criarInimigo(posX, posY));
					break;
				case 1317:
					get_listaPlataforma()->adicionarElemento(criarPlataforma(posX, posY));
					break;
				default:

					break;
				};
			}
		}
	}
}

void Fase::atualiza()
{

	

	//--Utilizando o gerenciadorGrafico--\\
	=======================================
	gerenciadorGrafico->draw();

	//----atualizando Jogadores----\\
	=================================
	for (Lista<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {

		(*it)->atualiza();
	}

	//----atualizando Inimigos----\\
	=================================
	for (Lista<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); ++it) {

		(*it)->atualiza();
	}

	//--atualizando ataques Jogadores--\\
	=====================================
	for (Lista<Jogador*>::iterator itJ = listaJogadores->begin(); itJ != listaJogadores->end(); ++itJ) {
		Lista<Ataque*>* listaAtaques = (*itJ)->get_listaAtaques();

		for (Lista<Ataque*>::iterator it = listaAtaques->begin(); it != listaAtaques->end();) {

			if ((*it)->OverTime()) {
				delete* it;										// Liberar memória
				it = listaAtaques->removerElemento(it);			// Remover elemento e atualizar iterador
			}
			else {
				(*it)->atualiza();
				++it;
			}

		}
	}

	//--atualizando ataques Inimigo--\\
	===================================
	for (Lista<Inimigo*>::iterator itI = listaInimigos->begin(); itI != listaInimigos->end(); ++itI) {

		Lista<Ataque*>* listaAtaquesInimigo = (*itI)->get_listaAtaques();
		for (Lista<Ataque*>::iterator it = listaAtaquesInimigo->begin(); it != listaAtaquesInimigo->end(); ) {

			if ((*it)->OverTime()) {
				delete* it;										// Liberar memória
				it = listaAtaquesInimigo->removerElemento(it);	// Remover elemento e atualizar iterador
			}
			else {
				(*it)->atualiza();
				++it;
			}
		}
	}

	gerenciadorColisao->tratarColisoes();
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

