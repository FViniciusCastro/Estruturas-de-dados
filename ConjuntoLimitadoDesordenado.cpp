//conjunto limitado desordenao via vetor
#include <iostream>

using namespace std;

struct Conjunto {

    char array[5];
    int n;

};

void inicializar(Conjunto &C) {

    C.n = 0;

}

bool vazio(Conjunto &C) {

    bool result = (C.n == 0) ? true : false;
    return result;

}

bool cheia(Conjunto &C) {

    bool result = (C.n >= 5) ? true : false;
    return result;

}

bool pertence(Conjunto &C, char elemento) {

    bool result;    
    for(int i = 0; i < 5; i++){

        result = (C.array[i] == elemento) ? true : false;

        if(result == true) {

            break;

        }    

    }

    return result;

}

void adicionarNovo(Conjunto &C, char elemento) {

    if(!cheia(C)){

        C.array[C.n++] = elemento;
        cout << "o elemento "<< elemento << " foi adicionado\n";

    } else {

        cout << "o conjunto já esta cheio, remova algum elemento para liberar espaço\n";

    }
}

void adicionarSeNovo(Conjunto &C, char elemento) {

    if(!pertence(C, elemento)){

        adicionarNovo(C, elemento);

    } else {

        cout << "o elemento " << elemento << " já pertence ao conjunto\n";

    }
}

void remover(Conjunto &C, char elemento) { 

    if(pertence(C, elemento)){

        for(int i = 0; i <= C.n ;i++) {

            if(C.array[i] == elemento){

                C.array[i] = C.array[C.n-1];    
                C.n--;

            }
        }
    } else {

        cout << "o elemento " << elemento <<" não pertence ao conjunto \n";

    }
}

void getConjunto(Conjunto &C) { // para teste

    for(int i = 0; i < C.n; i++){

        cout << C.array[i];
    }

    cout << endl;
}



int main(){

    Conjunto C;
    inicializar(C);

    adicionarNovo(C, 'A');
    adicionarNovo(C, 'B');
    adicionarNovo(C, 'C');
    adicionarNovo(C, 'D');
    adicionarNovo(C, 'E');
    adicionarNovo(C, 'F');

    getConjunto(C);

    remover(C, 'A');

    getConjunto(C);

    remover(C, 'B');
    remover(C, 'C');
    remover(C, 'D');

    getConjunto(C);

    remover(C, 'E');
    remover(C, 'E');

    getConjunto(C);



    return 0;
}
