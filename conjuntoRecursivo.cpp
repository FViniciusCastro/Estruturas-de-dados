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

int getIndex(Conjunto &C, int i, int f){
    
}

void inserir(Conjunto &C, char elemento) {
    
    if(!cheio(C)){
        
        
    } else cout << "impossivel inserir, conjunto cheioz\n";
}

void remover(Conjunto &C, char elemento) {
    if(!vazio(C)){ 
        if(C.n == 1) inicializar(C);
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
