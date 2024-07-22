// Fila Encadeada com Prioridade

#include <iostream>

using namespace std;

class Fila {

    struct Noh {
        int elem;
        Noh* prox;
    };
    Noh* inicio;
    Noh* fim;

public:
    Fila () {
        inicio = fim = nullptr;
    }

    int consultar() { // pré-condição: fila não vazia
        return inicio->elem;
    }

    bool vazio() {
        return (inicio == nullptr);
    }

    void enfilar(int elem) {

        Noh* novoNoh = new Noh{elem, nullptr};

        if (vazio()) inicio = novoNoh;
        else {
            fim->prox = novoNoh;
        }
        fim = novoNoh; 
    }

    void enfilarPrioridade(int elem) {

        Noh* novoNoh = new Noh{elem, nullptr};

        if (vazio()) fim = novoNoh;
        else {
                novoNoh->prox = inicio;
        }
        inicio = novoNoh;
    }

    void desenfilar() { // pré-condição: fila não vazia

        Noh* aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }

    ~Fila() { 

        while (inicio != nullptr) desenfilar();

    }
};


int main(){

    Fila fila;

    fila.enfilar(2);
    cout << fila.consultar() << endl;
    fila.enfilarPrioridade(3);
    cout << fila.consultar() << endl;
    fila.desenfilar();
    cout << fila.consultar() << endl;
}