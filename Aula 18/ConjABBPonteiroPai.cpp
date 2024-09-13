// conjunto via arvore binaria de busca com ponteiro para pai

#include<iostream>

using namespace std;

class ConjABB{
    struct Noh {
        Noh* pai;
        Noh* esq;
        double valor;
        Noh* dir; 
    };

    Noh* raiz;

public:

    ConjABB(){
        raiz = nullptr;
    }

    bool vazio() {return (raiz == nullptr); }

    Noh* inserir(double v){
        if(vazio()) return raiz;
        Noh* n = raiz;

        while(true) {
            if(v < n->valor) {
                if (n->esq == nullptr) return n->esq;
                n = n->esq;
            } else {
                if(n->dir == nullptr) return n->dir;
                n = n->dir;
            }
        }
    }

    void remover(Noh *r){
        Noh* *cima = &(r->pai);
        if(r->dir == nullptr) *cima = r->esq;
        else if (r->esq = nullptr) *cima = r->dir;
        else{
            Noh* s = r->dir;
            Noh* *cima_s = &r->dir;
            while (s->esq != nullptr){
                *cima_s = s->dir;
                s=s->esq;
            }
            *cima_s = s->dir;
            *cima_s = s->dir;
            *cima = s;
            s->esq = r->esq;
            s->dir = r->dir;
        }
        delete r; 
    }
};

