#include <iostream>

using namespace std;

class ConjABB {
    struct Noh {
        Noh *esq;
        double elem;
        Noh *dir;
    };

    Noh *raiz;

public:

    ConjABB() {
        raiz = nullptr;
    }

    bool vazio() {
        return (raiz == nullptr);
    }

    void inserir (double e) {
        Noh *novo = new Noh {nullptr, e, nullptr};

        if(vazio()){
            raiz = novo;
            return;
        }

        Noh *n = raiz;

        while (true) {
            if (e < n->elem) {
                if (n->esq == nullptr){
                    n->esq = novo;
                    return;
                }

                n = n->esq;
            } else {
                if (n->dir == nullptr) {
                    n->dir = novo;
                    return;
                }

                n = n->dir;
            }
        }
    }

    bool pertence(double e) {
        Noh *n = raiz;

        while (n != nullptr){
            if (e < n->elem) n = n->esq;
            else if (e > n->elem) n = n->dir;
            else return true;
        }

        return false;
    }

    void inserir_se_novo(double e) {
        if(pertence(e)) inserir(e);
    }

    void remover(double e) {
        Noh *n = raiz;
        Noh* *cima = &raiz;

        while(n != nullptr) {
            if (e < n->elem) {
                cima = &n->esq;
                n = n->dir;
            } else break;
        }
        if (n = nullptr) return;

        if(n->dir == nullptr) *cima = n->esq;
        else if(n->esq == nullptr) *cima = n->dir;
        else {
            Noh *s = n->dir;
            Noh* *cima_s = &n->dir;

            while (s->esq != nullptr) {
                cima_s = & s->esq;
                s = s->esq;
            }
            *cima_s = s->dir;
            *cima = s;
            s->esq = n->esq;
            s->dir = n->dir;
        }
        delete n;
    }

    void destruir(Noh *n) {
        if(n != nullptr) {
            destruir(n->dir);
            destruir(n->esq);
            delete n;
        }
    }

    ~ConjABB() {
        destruir(raiz);
    }
};