// dicionario via lista duplamente encadeada

#include<iostream>

using namespace std;

class Dicionario {
    struct Noh {
        Noh* esq;
        int chave;
        string valor;
        Noh* dir;
    };
    Noh* inicio;

public:

    Dicionario() {
        inicio = nullptr;
    }

    void inserir(int chave, string valor) {

        if(inicio == nullptr) inicio = new Noh{nullptr ,chave ,valor ,nullptr};
        else {
            Noh* novoNoh = new Noh {nullptr, chave, valor, inicio};
            inicio->esq = novoNoh;
            inicio = novoNoh;
        }
    }

    void inserirSeNovo(int chave, string valor) {

        ResConsulta resultado = consultar(chave);
        if (resultado.achou) return;
        else                 inserir(chave, valor);
    }

    struct ResConsulta {
        bool achou;
        string valor;
    };

    ResConsulta consultar(int chave) {

        Noh* aux = inicio;
        ResConsulta resultado = ResConsulta{false,};
        while(aux != nullptr){
            if(aux->chave == chave){
                resultado.achou = true;
                resultado.valor = aux->valor;
            }
            aux = aux->dir;
        }
    return resultado;
    }

    void remover(int chave) {

        Noh* aux = inicio;
        if(aux == nullptr) return;
        if(chave == aux->chave){
            removerInicio();
            return;
        }
        while(aux != nullptr) {
            if(aux->chave == chave){
                aux->dir->esq = aux->esq;
                aux->esq->dir = aux->dir;
                delete aux;
                return;
            }
            aux = aux->dir;
        }
    }

    void removerInicio() {
        
        Noh* aux = inicio;
        inicio = inicio->dir;
        delete aux;    
    }

    ~Dicionario() {
        while(inicio != nullptr){
            removerInicio();
        }
    }
};

int main(){
    Dicionario dicionario;

    dicionario.inserir(10, "valor 10");
    Dicionario::ResConsulta resultado = dicionario.consultar(10);
    cout << resultado.valor << endl;
    dicionario.inserir(20, "valor 20");
    dicionario.inserir(30, "valor 30");
    dicionario.inserir(40, "valor 40");
    dicionario.remover(30);
    Dicionario::ResConsulta resultado1 = dicionario.consultar(20);
    cout << resultado1.valor << endl;
    Dicionario::ResConsulta resultado2 = dicionario.consultar(30);
    cout << resultado2.valor << endl;
    Dicionario::ResConsulta resultado3 = dicionario.consultar(40);
    cout << resultado3.valor << endl;
    Dicionario::ResConsulta resultado4 = dicionario.consultar(10);
    cout << resultado4.valor << endl;
}