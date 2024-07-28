// Dicionário via lista encadeada com nó sentinela

#include <iostream>

using namespace std;

class Dicionario {

    struct Noh {

        int chave;
        string valor;
        Noh* prox;
    };

    Noh* sentinela;
    Noh* inicio;

public:

    Dicionario() {

        sentinela = new Noh{-1, "", nullptr};
        inicio = sentinela;
    }

    struct ResConsulta {

        bool achou;
        string valor;
    };

    ResConsulta consultar(int chave) {

        Noh* aux = inicio;
        ResConsulta resultado = ResConsulta{false,""};
        while(aux != sentinela){

            if(chave == aux->chave){
                resultado.achou = true;
                resultado.valor = aux->valor;
            }  
            aux = aux->prox; 
        }
        return resultado;
    }

    void inserir(int chave, string valor) {
        inicio = new Noh{chave, valor, inicio};
    }

    void inserirSeNovo(int chave, string valor) {

        if(consultar(chave).achou) return;
        else                       inserir(chave, valor);
    }

    void remover (int chave) {

        Noh* aux = inicio;
        if(aux == sentinela) return;
        if(aux->chave == chave) {removerInicio(); return;}
        while(aux != sentinela){

            aux = aux->prox;
            if(aux->prox->chave == chave){
                Noh* p = aux->prox;
                aux->prox = p->prox;
                delete p;
                return;
            }
        }
    }

    void removerInicio() {

        Noh* aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }

    ~Dicionario() {

        while(inicio != sentinela){
            removerInicio();
        }
    }
};

int main(){

    Dicionario dicionario;

    dicionario.inserir(10, "valor 10");
    dicionario.remover(10);
    dicionario.inserir(20, "valor 20");
    dicionario.inserir(30, "valor 30");
    dicionario.inserir(40, "valor 40");
    dicionario.remover(20);
    Dicionario::ResConsulta resultado1 = dicionario.consultar(20);
    cout << resultado1.valor << endl;
    Dicionario::ResConsulta resultado2 = dicionario.consultar(30);
    cout << resultado2.valor << endl;
    Dicionario::ResConsulta resultado3 = dicionario.consultar(40);
    cout << resultado3.valor << endl;
    Dicionario::ResConsulta resultado4 = dicionario.consultar(10);
    cout << resultado4.valor << endl;
}