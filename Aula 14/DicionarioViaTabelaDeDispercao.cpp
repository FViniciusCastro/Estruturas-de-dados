#include <iostream>

using namespace std;

class Dicionario {

    struct Noh {
        int chave;
        string valor;
        Noh* prox;
    };

    Noh** T;
    int m;

    int dispersora(int c) {
        return c % m;
    }

public:

    Dicionario(int tam) {

        m = tam;
        T = new Noh*[m];
        for (int i = 0; i < m; i++) {
            T[i] = nullptr;
        }
    }

    void inserir(int c, string v) {

        int indice = dispersora(c);
        T[indice] = new Noh{c, v, T[indice]};
    }

    void remover(int c) {

        int indice = dispersora(c);
        Noh* atual = T[indice];
        Noh* anterior = nullptr;

        while (atual != nullptr && atual->chave != c) {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == nullptr) {
            // Chave não encontrada
            return;
        }

        if (anterior == nullptr) {
            // O nó a ser removido é o primeiro da lista
            T[indice] = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        delete atual;
    }

    struct res_consulta {

        bool achou;
        string valor;
    };

    res_consulta consultar(int c) {

        res_consulta resposta{false, "chave não encontrada"};
        int indice = dispersora(c);
        Noh* cursor = T[indice];

        while (cursor != nullptr) {
            if (cursor->chave == c) {
                resposta.achou = true;
                resposta.valor = cursor->valor;
                break;
            }
            cursor = cursor->prox;
        }

        return resposta;
    }

    ~Dicionario() {

        for (int i = 0; i < m; i++) {
            while (T[i] != nullptr) {
                Noh* deletor = T[i];
                T[i] = T[i]->prox;
                delete deletor;
            }
        }
        delete[] T;
    }
};

int main() {
    Dicionario d(10);

    d.inserir(15, "valor1");
    d.inserir(24, "valor2");
    d.inserir(35, "valor3");

    Dicionario::res_consulta res = d.consultar(15);
    if (res.achou) {
        cout << "Chave 15 encontrada: " << res.valor << endl;
    } else {
        cout << "Chave 15 não encontrada" << endl;
    }

    res = d.consultar(24);
    if (res.achou) {
        cout << "Chave 24 encontrada: " << res.valor << endl;
    } else {
        cout << "Chave 24 não encontrada" << endl;
    }

    res = d.consultar(35);
    if (res.achou) {
        cout << "Chave 35 encontrada: " << res.valor << endl;
    } else {
        cout << "Chave 35 não encontrada" << endl;
    }

    d.remover(24);

    res = d.consultar(24);
    if (res.achou) {
        cout << "Chave 24 encontrada: " << res.valor << endl;
    } else {
        cout << "Chave 24 não encontrada após remoção" << endl;
    }

    return 0;
}
