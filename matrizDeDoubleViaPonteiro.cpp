/*Defina um tipo para representar uma matriz retangular m x n de double's (caso deseje, você pode usar os templates exemplificados nos exercícios da aula 07 (vídeo), em 04/04/2024, para implementar uma definição genérica quanto ao tipo dos elementos). Como estrutura de dados, utilize um vetor para representar as "m" linhas: cada uma das suas posições deve ser um ponteiro apontando para um vetor de "n" números. Escreva funções para ler das e escrever nas posições da matriz. Para testar a sua implementação, escreva um programa que leia do usuário duas matrizes de mesmas dimensões e que então calcule e imprima a soma dessas matrizes.*/

//exercício de greve


#include<iostream>

using namespace std;

struct Matriz{
    int m, n;
    double** altura;
    double* largura;


    Matriz(){ // constructor

        cout << "qual a altura da matriz?" << endl; 
        cin >> m;
        cout << "qual a largura da matriz?" << endl;
        cin >> n;

        //alocação da matriz
        altura = new double*[m];
        for(int i=0 ; i<m ; i++){
            altura[i] = new double[n];
        }
    }

    ~Matriz(){ // destructor
        for(int i=0 ; i<m ; i++){
            delete altura[i];
        }
        delete altura;
    }

    void reader(){ //leitor

    cout << "iniciando a leitura da matriz" << endl;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                cout << "digite o elemento da cordenada " << i+1 << "," << j+1 << ":" << endl;
                cin >>  altura[i][j];
            }
        }
    }

    double printer() { // impressor
        cout << endl << endl;
        for(int i=0 ; i<m ; i++){
            cout << "|";
            for(int j=0 ; j<n ; j++){
                cout << " "<< altura[i][j] << " ";
            }
            cout << "|"<< endl;
        }
    }
};

void somarMatrizes(Matriz matriz1, Matriz matriz2){

    if(matriz1.m != matriz2.m and matriz1.n != matriz2.n) {
        cout << "impossivel somar matrizes de tamanhos diferentes" << endl;
        return;
    }

    cout << endl <<  "a soma da matriz"; matriz1.printer();
    cout << endl << "com a matriz"; matriz2.printer();
    cout << endl << "resulta em:" << endl;

    for(int i=0 ;i < matriz1. m ;i++){
        cout << "|";
        for(int j=0 ; j<matriz1.n ; j++){
            matriz1.altura[i][j]+= matriz2.altura[i][j];
            cout << " " << matriz1.altura[i][j] << " ";
        }
        cout << "|" << endl;
    }

}

int main(){

    Matriz matriz1;
    Matriz matriz2;
    matriz1.reader();
    matriz1.printer();
    matriz2.reader();
    matriz2.printer();
    somarMatrizes(matriz1, matriz2);


}