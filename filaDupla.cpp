#include <iostream>

using namespace std;

struct Fila{
    
    char array1[5], array2[5];
    int p, n;
    
};

void inicializar(Fila &F){
    F.p = -1;
    F.n = 0;
} 

bool vazia (Fila &F){
    bool result = (F.n == 0) ? true : false;
    return result;
}

bool cheia (Fila &F){
    bool result = (F.n == 10) ? true : false;
    return result;
}

void enfilar(Fila &F, char elemento){
    
    if(!cheia(F)){
        
        if(vazia(F)) F.p = 0;
        int index = (F.p + F.n) % 10;
        if((F.p + F.n) % 10 <= 4) F.array1[index] = elemento;
        else F.array2[index-5] = elemento;
        F.n++;
        
    } else {
        cout << "fila cheia\n";
    }
}

void desenfilar(Fila &F){
    if(!vazia(F)){
        F.p = ++F.p % 10;
        
    } else {
        cout << "fila vazia\n";
    }
}

void consultar(Fila &F){
    
}

int main(){
    
    
    
    
    
    
    
    
    
    
    
    
}
