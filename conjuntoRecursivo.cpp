#include <iostream>

using namespace std;

struct Conjunto{
    
    char array[5];
    int n;
    
};

void inicializar(Conjunto &C) {
    C.n = 0;
}


bool cheio(Conjunto &C) {
    bool result = (C.n == 5) ? true: false;
    return result;
}

bool vazio(Conjunto &C) {
    bool result = (C.n == 0) ? true: false;
    return result;    
}

int getIndex(Conjunto &C, int i, int f, bool ~aux){
    if(i>=f){
        return -1;
    } else {
        int m =
        
    }
}

void inserir(Conjunto &C, char elemento) {
    
    if(!cheio(C)){
        int index = getIndex(C, 0, C.n-1);
        for(int i=C.n-1; i>=index; i--){
            C.array[i+1] = C.array[i];
        }
        C.n++;
        
    } else cout << "impossivel inserir, conjunto cheioz\n";
}

void remover(Conjunto &C, char elemento) {
    if(!vazio(C)){ 
        if(C.n == 1) inicializar(C);
        else if(index == -1) cout << "o elemento " << elemento <<" não pertence ao conjunto\n";
        else {
            int index = getIndex(C, 0, C.n-1);
            for(int i = index; i<C.n-1 ;i++){
                C.array[i] = C.array[i+1];
            }
            C.n--;
        }
    } else cout << "impossivel remover, conjunto vazio\n";
}














int main() {
    
}
