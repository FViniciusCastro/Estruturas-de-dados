// pilha com construtor e destrutor
#include <iostream>

using namespace std;

struct Pilha {
    string *v;
    int tam;
    int n;

    Pilha (){ // construtor
    cout <<endl <<  "construtor executando" << endl;
        tam = 1;
        v = new string[tam];
        n = 0;
    }

    ~Pilha(){ 
        delete[] v; 
        cout << endl << "destrutor execuando" << endl;
    } // destrutor

    bool vazia(){ return n == 0; }

    string topo(){ return v[n-1]; }

    void desempilhar(){ n--; }

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

    cout << "digite linhas terminando com uma vazia" << endl << endl;

    while(true){

        string linha; getline(cin, linha);

        if (linha == "") break;

        pilha.empilhar(linha);

    }

    cout << "linhas na ordem inversa : " << endl << endl;

    while(!pilha.vazia()){
        cout << pilha.topo() << endl;
        pilha.desempilhar();
    }

    return 0;

}