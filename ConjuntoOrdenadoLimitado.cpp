#include <iostream>

using namespace std;


struct Conjunto{
  
    char array[10];
    int n;
    
};

void inicializar(Conjunto &C) {
    
    C.n = 0;
    
}

bool cheia(Conjunto &C) {
    
    bool result = (C.n >= 10) ? true : false; 
    return result;
    
}

bool vazia(Conjunto &C) {
    
    bool result = (C.n == 0) ? true : false;
    return result;
    
}

bool pertence(Conjunto &C, char elemento) {
    
    int i = 0 , f = C.n-1;
    
    while(i < f) {
        
        int m = (i+f)/2;
        cout << "\n O MEIO É " << C.array[m] << endl << endl;
        if(C.array[m] == elemento){
            
            return true;
            
        } else if(C.array[m] > elemento) {
            
            i = ++m;
            
        } else {
            
            f = --m;
            
        }
    }
    return false;
    
}

void adicionarNovo(Conjunto &C, char elemento) {
    
    if(!cheia(C)){
        
        int maior = -1;
        for(int i = 0; i<C.n ;i++) {
                
            if(C.array[i] > elemento) {
                    
                maior = i;
                break;
                    
            }
        }
        cout << "o elemento " << elemento << " foi adicionado ";
        if(maior == -1){
                
            C.array[C.n] = elemento;
                
        } else {
            
            for(int i=C.n-1; i>=maior ; i--) {
                
                C.array[i+1] = C.array[i]; 
                
            }
            C.array[maior] = elemento;
            
        }
        C.n++;
            
        
    } else {
        
        cout << "conjunto já esta cheio\n";
        
    }
}

void adicionarSeNovo(Conjunto &C, char elemento) {
    
    if(!pertence(C, elemento)) {
        
        adicionarNovo(C, elemento);
        
    } else {
        
        cout << "elemento já  pertecente ao conjunto\n";
        
    }
}

void remover(Conjunto &C, char elemento) {
    
    if(pertence(C, elemento) and !vazia(C)) {
        
        int index = -1;
        for(int i = 0; i < C.n ; i++) {
            
            if(C.array[i] == elemento) {
                
                index = i;
                break;
                
            }
            for(int i = index ; i < C.n ;i++) {
                
                C.array[i] = C.array[i+1];
                
            }
           
        }
        C.n--;
        
    } else {
        
        cout << "o elemento não pertence ao conjunto ou o conjunto esta vazi0\n";
        
    }
}

void getConjunto(Conjunto &C) { // para teste

    for(int i=0 ; i<C.n ; i++){  
        
        cout << C.array[i];
        
    }
    cout << endl;
    
}



int main() {
    
    Conjunto C;
    inicializar(C);
    
    adicionarSeNovo(C, 'C');
    getConjunto(C);
    adicionarSeNovo(C, 'A');
    getConjunto(C);
    adicionarSeNovo(C, 'E');
    getConjunto(C);
    adicionarSeNovo(C, 'B');
    getConjunto(C);
    adicionarSeNovo(C, 'I');
    getConjunto(C);
    adicionarSeNovo(C, 'F');
    getConjunto(C);
    adicionarSeNovo(C, 'J');
    getConjunto(C);
    adicionarSeNovo(C, 'D');
    getConjunto(C);
    adicionarSeNovo(C, 'E');
    getConjunto(C);
    adicionarSeNovo(C, 'G');
    getConjunto(C);
    adicionarSeNovo(C, 'H');
    getConjunto(C);
    adicionarSeNovo(C, 'K');
    getConjunto(C);
    
}
