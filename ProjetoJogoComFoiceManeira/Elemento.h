#pragma once

template<class TE>	class Elemento
{
private:
	Elemento <TE>* pProx;
	TE* item;

public:
	Elemento();
	~Elemento();

	void set_pProx(Elemento<TE>* pProx) { this->pProx = pProx; }
	void set_item(TE* item) { this->item = item; }

	Elemento<TE>* get_pProx() { return pProx; }
	TE* get_item() { return item; }
};


template<class TE>
inline Elemento<TE>::Elemento()
{
	pProx = nullptr;
	item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{
}
