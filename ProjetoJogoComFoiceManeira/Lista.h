#pragma once

#include "Elemento.h"

template <class TL> class Lista {

private:
	
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;

	int len;

public:
	Lista();
	~Lista();

	int get_len() { return len; }

	TL* get_item(int posicao){
		Elemento<TL>* temp = pPrimeiro;

		if (posicao == 0) {
			return temp->get_item();
		}

		for (int i = 0; i < posicao; i++) {
			temp = temp->get_pProx();
		}

		return temp->get_item();
	}

	void push(TL* item) {
		if (pPrimeiro == NULL) {
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->set_item(item);
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>;
			temp->set_item(item);
			pUltimo->set_pProx(temp);
			pUltimo = temp;

		}
		len++;
	}

	void pop(TL* item) {
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = NULL;

		while (temp != NULL && temp->get_item() != item) {
			tempAnt = temp;
			temp = temp->get_pProx();
		}

		if (temp == pPrimeiro) {
			pPrimeiro = temp->get_pProx();
		}
		else if (temp == pUltimo) {
			tempAnt->set_pProx(NULL);
			pUltimo = tempAnt;
		}
		else {
			tempAnt->set_pProx(temp->get_pProx());
		}

		delete temp;
		len--;

	}

};

template<class TL>
inline Lista<TL>::Lista()
{
	pPrimeiro = NULL;
	pUltimo = NULL;

	len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{
}
