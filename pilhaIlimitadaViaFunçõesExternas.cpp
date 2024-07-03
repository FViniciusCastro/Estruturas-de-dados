#include <iostream>

using namespace std;

struct Pilha{
    string *v;
    int tam;
    int n;
};

void inicializar(Pilha &p){
    p.tam = 1;
    p.v = new string[p.tam];
    p.n = 0;
}

bool vazia(Pilha &p){
    return p.n ==0;
}

string topo(Pilha &p){
    return p.v[p.n-1];
}

void desempilhar(Pilha &p){
    p.n--;
}

void empilhar(Pilha &p, string linha){

    if(p.n == p.tam){

        int tam2 = p.tam*2;
        string* w = new string[tam2]; // criando novo ponteiro e apontando para novo vetor 2* maior que o anterior

        for(int i = 0 ; i < p.n ; i++) w[i] = p.v[i]; // copiando os endereços de cada variavel

        delete p.v; // deletando o enndereço antigo
        p.v = w; // copiando o endereço novo
        p.tam = tam2; // mudando o tamanho
      
    }
    p.v[p.n] = linha; 
    p.n++; // adicionando nova linha e aumentando o n

}

void terminar(Pilha &p){
    delete[] p.v;
}

int main(){

    Pilha pilha;
    inicializar(pilha);

    cout << "digite linhas terminando com uma vazia" << endl;

    while(true){

        string linha; getline(cin, linha);

        if (linha == "") break;

        empilhar(pilha, linha);

    }

    while(!vazia(pilha)){
        cout << topo(pilha) << endl;
        desempilhar(pilha);
    }

    terminar(pilha);
    return 0;

}