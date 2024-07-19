// fila via vetor dinâmico
#include <iostream>

using namespace std;

struct Fila {

    int size, p, u;
    char array[];

};

void setTamanho(Fila &F){

    int size;
    cout << "qual o tamanho da fila?" << endl;
    cin >> size;

    F.size = size;
    F.array[F.size];

}


 void inicializar(Fila &F) {

    setTamanho(F);

    F.u = -1;
    F.p = -1;

}


bool cheia(Fila &F) {

    bool result;

    if(F.p > F.u and (F.p - F.u) == 1) {
        result = true;
    } else if (F.p < F.u and (F.u - F.p) == F.size - 1) {
        result = true;
    }

    return result;

}

bool vazia(Fila &F) {

    bool result = (F.p == -1) ? true : false;
    return result;

}

void enfilar(Fila &F) {

    if(!cheia(F)){

        char elemento;

        cout << "qual elemento deseja enfilar? \n";
        cin >> elemento;

        if(F.p == -1){
            F.p = 0;
        } 

        F.u++;

        if(F.u == F.size){
            F.u = 0;
        }

        F.array[F.u] = elemento;

        cout << "o elemento " << elemento << " foi adicionado ao espaço " << F.u << endl;

    } else {
        cout << "fila esta cheia. Impossivel adicionar elemento\n";
    } 
}

void desenfilar(Fila &F) {

    if(!vazia(F)){

        cout << "o elemento " << F.array[F.p] << " foi removido do espaço " << F.p << endl;

        F.array[F.p] = ' ';
        if(F.p == F.size){
            F.p = 0;
        } 
        if(F.p == F.u){
            F.p = -1;
            F.u = -1;
        } else {
            F.p++;
        }

    } else {
        cout << "fila já está vazia\n";
    }

}

void consultar(Fila &F) {

  cout << "o primeiro elemento é:" << F.array[F.p] << endl;

}


void getFila(Fila &F) { // para testes

    for(int i = 0; i < F.size ;i++){

        cout << F.array[i];

    }

    cout << endl;

}



int main() {

    Fila F;
    inicializar(F);

    int opc = -1;

    while(opc != 0) {
        cout << "\n==============MENU=============\n" << endl;
        cout << "escolha uma opção\n\n    1 - enfilar\n    2 - desenfilar\n    3 - consultar\n    0 - encerrar programa\n\n";
        cin >> opc;

        switch(opc){
            case 1:
                enfilar(F);
                break;
            case 2:
                desenfilar(F);
                break;
            case 3: 
                consultar(F);
                break;
            case 0:
                break;
            default:
                cout << "opção invalida\n\n";
                break;
        }
    }



}
