// fila via lista encadeada
#include <iostream>

using namespace std;

struct Fila{
    struct Noh{
        int elem;
        Noh* prox;
    };
    Noh* inicio;
    Noh* fim;

    Fila() {
        fim = inicio = nullptr;
    }

    int consultar() {
        return inicio->elem;
    }

    void enfilar(int elem) {

        Noh* novoNoh = new Noh {elem, nullptr};
        if (fim == nullptr) inicio = novoNoh;  
        else                fim->prox = novoNoh;
        fim = novoNoh;

    }

    void desenfilar() {
        Noh* aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }

    ~Fila(){
        while(inicio != nullptr) desenfilar();
    }
};


int main(){

    Fila fila;

    fila.enfilar(1);
    cout << "inicio :" << fila.consultar() << endl;
    fila.enfilar(2);
    cout << "inicio :" << fila.consultar() << endl;
    fila.desenfilar();
    cout << "inicio :" << fila.consultar() << endl;

}