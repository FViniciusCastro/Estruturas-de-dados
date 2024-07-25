// dicionário via lista encadeada

#include <iostream>

using namespace std;

class Dicionario {
    struct Noh {
        int chave;
        string valor;
        Noh* prox;
    };
    Noh* inicio;
public:

    Dicionario() {
        inicio = nullptr;
    }

    void inserir(int chave, string valor) {
        inicio = new Noh{chave, valor, inicio};
    }

    void inserirSeNovo(int chave, string valor){
        ResConsulta resultado = consultar(chave);
        if(!resultado.achou) inserir(chave, valor);
    }

    void remover(int chave) {

        Noh* aux = inicio;
        if (aux == nullptr) return;
        if (aux->chave == chave) {
            removerInicio();
            return;
        }
        while(aux->prox != nullptr){
            if(aux->prox->chave == chave){

                Noh* p = aux->prox;
                aux->prox = p->prox;
                delete p;
                return;
            }
            aux = aux->prox;
        }
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
                break;
            }
            aux = aux->prox;
        }
        return resultado;
    } 

    void removerInicio(){
        Noh* aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }

    ~Dicionario() {
        while(inicio != nullptr){
            removerInicio();
        }
    }

};


int main() {


    Dicionario dicionario;

    dicionario.inserir(10, "valor 10");
    Dicionario::ResConsulta resultado = dicionario.consultar(10);
    cout << resultado.valor << endl;
    dicionario.remover(10);
    dicionario.inserir(20, "valor 20");
    dicionario.inserir(30, "valor 30");
    dicionario.inserir(40, "valor 40");
    Dicionario::ResConsulta resultado1 = dicionario.consultar(20);
    cout << resultado1.valor << endl;
    Dicionario::ResConsulta resultado2 = dicionario.consultar(30);
    cout << resultado2.valor << endl;
    Dicionario::ResConsulta resultado3 = dicionario.consultar(40);
    cout << resultado3.valor << endl;
    Dicionario::ResConsulta resultado4 = dicionario.consultar(10);
    cout << resultado4.valor << endl;

}