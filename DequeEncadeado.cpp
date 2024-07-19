// deque via lista encadeada
#include <iostream>

using namespace std;

class Deque {
    struct Noh {
        Noh* esquerda;
        int elem;
        Noh* direita;
    };
    Noh* esq; 
    Noh* dir;

public:
    Deque() {
        esq  = dir = nullptr;
    }

    void enfilarUnico(int elem) {
        dir = esq = new Noh {nullptr, elem, nullptr};
    }

    void desenfilarUnico() {

    }

    bool vazio(){
        return (dir == nullptr and esq == nullptr);
    }

    void enfilarDir(int elem) {

        if(vazio()) enfilarUnico(elem);
        else {
                dir->direita = new Noh {dir, elem, nullptr};
                dir = dir->direita;
        }
    }

    
    void enfilarEsq(int elem) {

        if(vazio()) enfilarUnico(elem);
        else {
            esq->esquerda = new Noh {nullptr, elem, esq};
            esq = esq->esquerda;
        } 
    }


    void desenfilarDir() {
        Noh* aux = dir;
        dir = dir->esquerda;
        dir->direita = nullptr;
        delete aux;

    }

    void desenfilarEsq() {
        Noh* aux = esq;
        esq = esq->direita;
        esq->esquerda = nullptr;
        delete aux;
    }

    int consultarDir() {
        return dir->elem;
    }

    int consultarEsq() {
        return esq->elem;
    }


    ~Deque() {
        while(dir != nullptr){
            desenfilarEsq();
        }
    }
};

int main() {
    Deque deque;
    deque.enfilarEsq(1);
    deque.enfilarEsq(2);
    cout << "esquerda: " << deque.consultarEsq() << endl;
    cout << "direita: " << deque.consultarDir() << endl;
    deque.enfilarDir(3);
    cout << "direita: " << deque.consultarDir() << endl;
    deque.desenfilarDir();
    cout << "esquerda: " << deque.consultarEsq() << endl;
    cout << "direita: " << deque.consultarDir() << endl;   
}