
#include <iostream>
#define size 5

using namespace std;


struct Fila {
    char array[size];
    int p, u, cont;
};

void inicializar(Fila &F){
    for(int i = 0;i < size; i++){
        F.array[i] = ' ';
    }
    F.p = -1;
    F.cont = 0;
}

bool vazia(Fila &F){

    bool result = (F.p == -1 ) ? true : false;

    return result;
}

bool cheia(Fila &F){

  bool result = false;;

  if(F.cont == size){
    result = true;
  }
  
  return result;
}

void inserir(Fila &F, char letra){

    if(!cheia(F)){
      if(F.p == -1){
          F.p = 0;
          F.u = 0;
      }
      F.array[F.u] = letra;
      F.cont++;
      cout << "A letra " << letra << " foi inserida com sucesso no espaço " << F.u << endl;
      F.u++;
      if(F.u > 4){
          F.u = 0;
      }
    } else {
        cout << "A fila esta cheia. Remova caracteres para ser possivel a adição de novos\n";
    }
}

void remover(Fila &F){
  cout << "A letra " << F.array[F.p] << " foi removida com sucesso no espaço " << F.p << endl;
  F.array[F.p] = ' ';
  F.cont--;
  F.p++;
  if(F.p > 4){
      F.p = 0;
  }
  if(F.p == F.u){
      F.p = -1;
  }

}

void getFirst(Fila &F){
  cout << "A primeira letra da fila é: " << F.array[F.p] << endl;
}

void getFila(Fila &F){
  for(int i = 0; i<size ; i++){
    cout << F.array[i];
  }
  cout << endl;
}

int main() {

  Fila F;
  inicializar(F);
  inserir(F, 'A');
  inserir(F, 'B');
  inserir(F, 'C');
  inserir(F, 'D');
  inserir(F, 'E');
  getFila(F);
  remover(F);
  getFila(F);
  inserir(F, 'F');
  remover(F);
  getFila(F);
  inserir(F, 'G');
  getFila(F);
  remover(F);
  remover(F);
  inserir(F, 'H');
  inserir(F, 'I');
  inserir(F, 'J');
  getFila(F);
  getFirst(F);
  

  return 0;
}
