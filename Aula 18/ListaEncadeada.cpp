// Lista encadeada com ponteiro para ponteiro

#include <iostream>

using namespace std;

class Lista {  
    struct Noh {
        int valor;
        Noh* prox;
    };
    Noh* inicio;

public:

    Lista() {
        inicio = nullptr;
    }

    void inserir(int v){
        inicio = new Noh{v,inicio->prox};
    }

    void remover (int v){
        Noh* *ant = &inicio;
        while(ant != nullptr){
            if((*ant)->valor == v){
                Noh *remover = *ant;
                delete remover;
            }
            ant = &(*ant)->prox;
        }
    };

    ~Lista() {
        while(inicio != nullptr) {
            Noh* prox = inicio->prox;
            delete inicio;
            inicio = prox;
        }
    }
};