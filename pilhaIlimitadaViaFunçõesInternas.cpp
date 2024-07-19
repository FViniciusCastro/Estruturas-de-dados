// pilha via funções externas
#include <iostream>

using namespace std;

struct Pilha{
    string *v;
    int tam;
    int n;

    void inicializar(){
        tam = 1;
        v = new string[tam];
        n = 0;
    }

    bool vazia(){ return n == 0; }

    string topo(){ return v[n-1]; }

    void desempilhar(){ n--; }

    void terminar(){ delete[] v; }

    void empilhar(string linha){

        if(n == tam){

            int tam2 = tam*2;
            string* w = new string[tam2];

            for(int i = 0 ; i < n ; i++) w[i] = v[i];

            delete v;
            v = w;
            tam = tam2;
        
        }
        v[n] = linha;
        n++;

    }
}; // struct Pilha

int main(){

    Pilha pilha;
    pilha.inicializar();

    cout << "digite linhas terminando com uma vazia" << endl;

    while(true){

        string linha; getline(cin, linha);

        if (linha == "") break;

        pilha.empilhar(linha);

    }

    while(!pilha.vazia()){
        cout << pilha.topo() << endl;
        pilha.desempilhar();
    }

    pilha.terminar();
    return 0;

}