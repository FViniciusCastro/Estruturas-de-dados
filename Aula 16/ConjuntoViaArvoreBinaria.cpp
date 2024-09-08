// Conjunto via arvore binaria de busca
#include<iostream>

using namespace std;

class Arvore {
    struct Noh {
        Noh* esq;
        int valor;
        Noh* dir;
    };
    Noh* raiz;

public:
    Arvore() {
        raiz = nullptr;
    }

    Noh* ordenar(int* vetor, int tamanho) {
        int meio = tamanho / 2;
        if (tamanho == 0)
            return nullptr;

        Noh* pai = new Noh;
        pai->valor = vetor[meio];

        pai->esq = ordenar(vetor, meio);
        pai->dir = ordenar(&vetor[meio + 1], tamanho - meio - 1);

        return pai;
    }

    void construir(int* vetor, int tamanho) {
        raiz = ordenar(vetor, tamanho);
    }
};

int main() {
    
    int vetor[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    Arvore arvore;

    arvore.construir(vetor, tamanho);

    cout << "Arvore criada com sucesso." << endl;

    return 0;
}
