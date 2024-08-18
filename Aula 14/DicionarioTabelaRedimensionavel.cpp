#include <iostream>

using namespace std;

class Dicionario {

    struct Noh {
        int chave;
        string valor;
        Noh* prox;
    };

    Noh** T;
    int tam, n;

    int dispersora(int c) {
        return c % tam;
    }

    void redimencionar(int novoTam) {

        Noh** novoT = new Noh*[novoTam];
        for (int i = 0; i < novoTam; i++) {
            novoT[i] = nullptr;
        }

        for (int i = 0; i < tam; i++) {
            Noh* cursor = T[i];
            while (cursor != nullptr) {
                Noh* prox = cursor->prox;
                int novoIndex = cursor->chave % novoTam;
                cursor->prox = novoT[novoIndex];
                novoT[novoIndex] = cursor;
                cursor = prox;
            }
        }

        delete[] T;
        T = novoT;
        tam = novoTam;
    }

public:

    Dicionario() {

        tam = 1;
        n = 0;
        T = new Noh*[tam];
        T[0] = nullptr;
    }

    void inserir(int c, string v) {

        if (n == tam) redimencionar(2 * tam);
        int index = dispersora(c);
        T[index] = new Noh{c, v, T[index]};
        n++;
    }

    void inserirSeNovo(int c, string v) {
        if (!consultar(c).achou) inserir(c, v);
    }

    void remover(int c) {

        int index = dispersora(c);
        Noh* cursor = T[index];
        Noh* anterior = nullptr;

        if (cursor == nullptr) return;
        while (cursor != nullptr and cursor->chave != c) {
            anterior = cursor;
            cursor = cursor->prox;
        }

        if (anterior == nullptr) {
            T[index] = cursor->prox;
        } else {
            anterior->prox = cursor->prox;
        }

        delete cursor;
        n--;

        if (n > 0 and n <= tam / 4) redimencionar(tam / 2);
    }

    struct res_consulta {

        bool achou = false;
        string valor = "chave não cadastrada";
    };

    res_consulta consultar(int c) {

        int index = dispersora(c);
        res_consulta resultado;
        Noh* cursor = T[index];
        while (cursor != nullptr) {
            if (cursor->chave == c) {
                resultado.achou = true;
                resultado.valor = cursor->valor;
                break;
            }
            cursor = cursor->prox;
        }
        return resultado;
    }

    ~Dicionario() {

        for (int i = 0; i < tam; i++) {
            Noh* cursor = T[i];
            while (cursor != nullptr) {
                Noh* prox = cursor->prox;
                delete cursor;
                cursor = prox;
            }
        }
        delete[] T;
    }
};

int main() {
    Dicionario dic;

    dic.inserir(1, "um");
    dic.inserir(2, "dois");
    dic.inserir(3, "três");
    dic.inserir(4, "quatro");

    auto resultado1 = dic.consultar(1);
    auto resultado2 = dic.consultar(2);
    auto resultado3 = dic.consultar(5); 

    cout << "Consulta chave 1: " << (resultado1.achou ? resultado1.valor : "chave não encontrada") << endl;
    cout << "Consulta chave 2: " << (resultado2.achou ? resultado2.valor : "chave não encontrada") << endl;
    cout << "Consulta chave 5: " << (resultado3.achou ? resultado3.valor : "chave não encontrada") << endl;

    dic.remover(2);

    auto resultado4 = dic.consultar(2);
    cout << "Consulta chave 2 após remoção: " << (resultado4.achou ? resultado4.valor : "chave não encontrada") << endl;

    dic.inserir(5, "cinco");
    dic.inserir(6, "seis");
    dic.inserir(7, "sete");

    auto resultado5 = dic.consultar(5);
    cout << "Consulta chave 5: " << (resultado5.achou ? resultado5.valor : "chave não encontrada") << endl;

    return 0;
}
