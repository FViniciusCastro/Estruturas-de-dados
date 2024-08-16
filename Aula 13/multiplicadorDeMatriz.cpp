#include <iostream>

using namespace std;

class Matriz {

    int linhas, colunas;
    double** M;

public:

    Matriz(int l, int c){

        setSize(l, c);
        M = new double* [l];
        for (int i = 0; i < l; i++){
            M[i] = new double[c];
        }
    }

    void setSize(int l, int c) {
        linhas = l;
        colunas = c;
    }

    int getLinhas() {
        return linhas;
    }

    int getColunas() {
        return colunas;
    }

    void setElemento(double elem, int l, int c) {
        M[l][c] = elem;
    }

    double getElemento(int l, int c) {
        return M[l][c];
    }

    ~Matriz() {
        for(int i = 0; i < linhas; i++) {
            delete[] M[i];
        }
        delete[] M;
    }
};

class Multiplicador {

    Matriz *mat1, *mat2;

public:

    Multiplicador (Matriz* m1, Matriz* m2) {
        mat1 = m1;
        mat2 = m2;
    }

    bool compativel() {
        return (mat1->getColunas() == mat2->getLinhas());
    }

    struct produto{
        bool compativel = false;
        Matriz* mat = nullptr;
    };

    produto multiplicar() {
        produto resultado;
        if(compativel()) {  
            resultado.compativel = true;
            resultado.mat = new Matriz(mat1->getLinhas(), mat2->getColunas());  
            for(int i = 0; i < mat1->getLinhas(); i++){
                for(int j = 0; j < mat2->getColunas(); j++){  
                    double soma = 0.0;
                    for(int k = 0; k < mat1->getColunas(); k++){  
                        soma += mat1->getElemento(i,k) * mat2->getElemento(k, j);
                    }
                    resultado.mat->setElemento(soma, i, j);
                }
            }
        }
        return resultado; 
    } 

    ~Multiplicador() {
    }
};

int main() {
  
    Matriz* mat1 = new Matriz(2, 2);
    Matriz* mat2 = new Matriz(3, 3);


    mat1->setElemento(1, 0, 0);
    mat1->setElemento(2, 0, 1);
    mat1->setElemento(4, 1, 0);
    mat1->setElemento(5, 1, 1);


    mat2->setElemento(1, 0, 0);
    mat2->setElemento(1, 0, 1);
    mat2->setElemento(1, 1, 0);
    mat2->setElemento(1, 1, 1);
    mat2->setElemento(1, 2, 0);
    mat2->setElemento(1, 2, 1);
    mat2->setElemento(1, 2, 0);
    mat2->setElemento(1, 2, 1);

    Multiplicador multiplicador(mat1, mat2);

    Multiplicador::produto resultado = multiplicador.multiplicar();

    if (resultado.compativel) {
        cout << "Matrizes multiplicadas com sucesso!" << endl;
        for (int i = 0; i < resultado.mat->getLinhas(); i++) {
            for (int j = 0; j < resultado.mat->getColunas(); j++) {
                cout << resultado.mat->getElemento(i, j) << " ";
            }
            cout << endl;
        }
    } else {
        cout << "As matrizes não são compatíveis para multiplicação!" << endl;
    }
}
