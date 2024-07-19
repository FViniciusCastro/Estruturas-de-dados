#include <iostream>

using namespace std;

struct Pilha{

    struct Noh {
        int elem;
        Noh* prox;
    };
    Noh* topo;

    Pilha() {
        topo = nullptr;
    }

    void empilhar(int e) {
        topo = new Noh{e , topo};
    }

    int consultarTopo() {
        return topo->elem;
    }

    void desempilhar () {

        Noh* primeiro = topo;
        topo = topo->prox;
        delete primeiro;

    }

    ~Pilha() {
        while(topo != nullptr){ 
            desempilhar();
        }
    }
};

int main(){
    Pilha pilha;

    pilha.empilhar(1);
    cout << pilha.consultarTopo() << endl;
    pilha.empilhar(2);
    cout << pilha.consultarTopo() << endl;
    pilha.desempilhar();
    cout << pilha.consultarTopo() << endl;

}