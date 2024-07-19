// dicionario ordenado via vetor estático
#include <iostream>

using namespace std;

struct Dicionario {
    
    int chave[5];
    char array[5];
    
};

void inicializar(Dicionario &D){
    
    for(int i=0; i < 5; i++){
        
        D.chave[i] = -1;
        D.array[i] = ' ';
    }
}

void inserir(Dicionario &D, int chave, char valor){
    
    if(chave > 5 or chave < 0){
        cout << "chave invalida\n";
    } else if(D.chave[chave] != chave){
     
        D.chave[chave] = chave;
        D.array[chave] = valor;
        
    } else {
        cout << "a chave já está cadastrada com o valor " << D.array[chave] << endl;
    }
}

bool existe(Dicionario &D, int chave){
    
    bool result = (D.chave[chave] == chave) ? true : false;
    return result;
}

void remover(Dicionario &D, int chave){

    if(existe(D, chave)){
        
        cout << "a chave " << D.chave[chave] << " e o valor " << D.array[chave] << " foram removidos\n";
        D.array[chave] = ' ';
        D.chave[chave] = -1;
        
    } else {
        cout << "chave não registrada\n";
    }
}

void consultar(Dicionario D,int chave){ 
    
    if(existe(D, chave)){
        
        cout << "o valor atribuido a chave " << chave << " é " << D.array[chave] << endl;
        
    } else {
        cout << "a chave " << chave << " não está cadastrada\n";
    }
} 



int main(){
    
    Dicionario D;
    inicializar(D);
    
    int opc = -1;
    int chave;
    char valor;
    
    while (opc != 0){
        
        cout << "===================MENU======================\n\nescolha a operação:\n1 - inserir\n2 - remover\n3 - consultar\n0 - encerrar programa\n";
        cin >> opc;
        
        switch (opc){
            case 1:
                cout << "digite a chave(entre 0 e 4):\n";
                cin >> chave;
                cout << "digite o valor:\n";
                cin >> valor;
                inserir(D, chave, valor);
                break;
            case 2:
                cout << "digite a chave(entre 0 e 4):\n";
                cin >> chave;
                remover(D, chave);
                break;
            case 3:
                cout << "digite a chave(entre 0 e 4):\n";
                cin >> chave;
                consultar(D, chave);
                break;
            case 0:
                cout << "programa encerrado, volte sempre :)\n";
                break;
            default:
                cout <<"operação invalida\n";
                break;
        }
    }
}

