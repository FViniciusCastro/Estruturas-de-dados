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

int getIndex(Conjunto &C, char elemento, int i, int f, bool aux){
    if(i >= f) return -1;
    else {
        int m =(i+f)/2;
        if(C.array[m] == elemento or (C.array[m] < elemento and C.array[m+1] > elemento and aux == true)) 
            return m;
        else if(C.array[m] < elemento) 
            return getIndex(C, elemento, m+1, f, aux);
        else
            return getIndex(C, elemento, i, m-1, aux);
    }
}

void inserir(Conjunto &C, char elemento) {
    
    if(!cheio(C)){
        int index = getIndex(C, elemento, 0, C.n-1, true);
        for(int i=C.n-1; i>=index; i--){
            C.array[i+1] = C.array[i];
        }
        cout << "o elemento " << elemento <<" foi adicionado ao espaço " << index << endl;
        C.array[index] = elemento;
        C.n++;
        
    } else cout << "impossivel inserir, conjunto cheioz\n";
}

void remover(Conjunto &C, char elemento) {
    int index = getIndex(C, elemento, 0, C.n-1, false);
    if(!vazio(C)){ 
        if(C.n == 1) inicializar(C);
        else if(index == -1) cout << "o elemento " << elemento <<" não pertence ao conjunto\n";
        else {
            for(int i = index; i<C.n-1 ;i++){
                C.array[i] = C.array[i+1];
            }
            cout << "o elemento" << elemento << "foi removido\n";
            C.n--;
        }
    } else cout << "impossivel remover, conjunto vazio\n";
}




int main() {
    
    Conjunto C;
    inicializar(C);
    
    inserir(C, 'A');
    inserir(C, 'B');
    inserir(C, 'C');
    inserir(C, 'D');
    inserir(C, 'E');
    
    cout << C.array[0] << endl;
    cout << C.array[1] << endl;
    cout << C.array[2] << endl;
    
    
    
    
    
}
