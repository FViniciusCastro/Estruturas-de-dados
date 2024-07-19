#include <iostream>
#include <cctype>

using namespace std;

struct Dicionario {
    int tam;
    int n;
    string *v;

    Dicionario(){ // construtor
        tam = 1;
        n = 0;
        v = new string[tam];
    }

    ~Dicionario(){ // destrutor
        delete v;
    }

    bool vazia () { return (n == 0); }

    bool cheia () { return (n == tam); }

    void adicionar (string palavra){

    for (char &c : palavra) {
        c = tolower(c);
    }
        
        
        if (n == tam){
        
            int tam2 = 2*tam;
            string* w = new string[tam2];

            for(int i = 0; i < tam ; i++){ w[i] = v[i];}

            delete v;
            v = w;
            tam = tam2;

        }

        v[n] = palavra;
        n++;
    }

    void printer(){

        for(int i = 0; i < n ; i++){
            cout << v[i] << endl;
        }
    }



}; // struct Dicionario

int main (){

    string texto;
    cout << "digite um texto";
    getline(cin, texto);

}
