#include <iostream>
#define size 5

using namespace std;

struct Pilha {

  char array[size];
  int p, u, cont;

};

void inicializarPilha(Pilha &P){

  for(int i=0 ; i<size ; i++){

    P.array[i] = ' ';

  }

  P.p = -1;
  P.u = -1;
  P.cont = 0;
}

bool vazia(Pilha &P){

  bool result = (P.cont == 0) ? true : false;

  return result;
}

bool cheia(Pilha &P){

    bool result = (P.cont == size) ? true : false;

    return result; 
}

void inserir(Pilha &P, char letra){

    if (!cheia(P)){

        if(P.u == -1){
            P.u++;
            P.p++;
        }

        P.array[P.u] = letra;
        cout << "a letra " << letra << " foi adicionada ao espaço " << P.u << endl;
        P.u++;
        P.cont++;

    } else {

        cout << "a pilha está cheia. Remova algum elemento para liberar espaço\n";
    }
}

void remover(Pilha &P){

    if(!vazia(P)){

        cout << "a letra " << P.array[P.u] << " foi removida do espaço " << P.u << endl;
        P.array[P.u] = ' ';
        P.u--;
        P.cont--;

    } else {

        cout << "a pilha já esta vazia";
    }
}

void getPilha(Pilha &P){
    for(int i=0; i<size ;i++){
        cout << P.array[i];
    }
    cout << endl;
}

void getLast(Pilha &P){
    cout << "o ultimo elemento da pilha é " << P.array[P.u - 1] << endl;
}

int main() {
    Pilha P;
    inicializarPilha(P);
    inserir(P, 'A');
    inserir(P, 'B');
    getLast(P);
    getPilha(P);
    remover(P);
    inserir(P, 'C');
    inserir(P, 'D');
    inserir(P, 'E');
    inserir(P, 'F');
    inserir(P, 'G');
    getLast(P);
    remover(P);
    remover(P);
    getPilha(P);


}
