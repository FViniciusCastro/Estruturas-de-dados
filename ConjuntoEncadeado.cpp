// Conjunto circular via lista duplamente encadeado com nó sentinela

#include<iostream>

using namespace std;

class Conjunto {

    struct Noh{
        Noh* esq;
        int elemento;
        Noh* dir;
    };
    Noh sentinela;

public:

    Conjunto() {

        sentinela.dir = &sentinela;
        sentinela.esq = &sentinela;
    }

    bool Consultar(int elemento) {

        sentinela.elemento = elemento;
        Noh* cursor = sentinela.dir;
        while(cursor->elemento != elemento){
            cursor = cursor->dir;
        }
        return !(cursor == &sentinela);
    }

    void inserir(int elemento) {

        Noh* novoNoh = new Noh{&sentinela, elemento, sentinela.dir};
        sentinela.dir = novoNoh;
        novoNoh->dir->esq = novoNoh;
    }

    void iserirSeNovo(int elemento) {

        if(Consultar(elemento)) return;
        else inserir(elemento);
    }

    void remover(int elemento) {

        sentinela.elemento = elemento;
        Noh* cursor = sentinela.dir;
        while(cursor->elemento != elemento){
            cursor = cursor->dir;
        }
        if(cursor == &sentinela) return;
        cursor->esq->dir = cursor->dir;
        cursor->dir->esq = cursor->esq;
        delete cursor;
    }

    ~Conjunto() {
        Noh* cursor = sentinela.dir;
        while(sentinela.dir != &sentinela){
            cursor->dir->esq = cursor->esq;
            cursor->esq->dir = cursor->dir;
            delete cursor;
        }
    }
};


int  main() {
    Conjunto conjunto;

    conjunto.inserir(2);
    conjunto.remover(2);
    bool achou = conjunto.Consultar(2);
    conjunto.inserir(3);
    conjunto.inserir(4);
    achou = conjunto.Consultar(4);
    conjunto.iserirSeNovo(4);
    conjunto.iserirSeNovo(5);
    achou = conjunto.Consultar(5);


    if (achou) cout << "achou" << endl;
    else cout << "nao achou" << endl;
}