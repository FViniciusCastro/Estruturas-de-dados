//somador de matriz via alocação dinamica
#include <iostream>

using namespace std;

class Matriz {

    double **M;

public:

    int linhas, colunas;
   
    Matriz(int num_l, int num_c) {

        linhas = num_l;
        colunas = num_c;
        M = new double* [linhas];
        for(int i = 0; i < linhas; i++){  
            M[i] = new double [colunas]; 
        }
    }

    double& getElemento(int l, int c){
        return M[l][c];
    }

    void setElemento(double elem, int l, int c){
        M[l][c] = elem;
    }

    ~Matriz() {
        for(int i = 0; i < linhas; i++){  
            delete[] M[i];
        }
        delete[] M;
    }

};

class Somador {

    Matriz* mat1,* mat2;

public:

    Somador(Matriz* matriz_1, Matriz* matriz_2) {

        mat1 = matriz_1;
        mat2 = matriz_2;

    }

    bool compativel() {

        if (mat1->linhas == mat2->linhas && mat1->colunas == mat2->colunas) return true;
        return false;
    }

    struct res_soma {
        bool compativel;
        Matriz* matriz;
    };

    res_soma somar(){

        res_soma resultado {false, nullptr};
        if (compativel()) {  

            for(int i = 0; i < mat1->linhas; i++){  
                for (int j = 0; j < mat2->colunas; j++){  
                    mat1->setElemento(mat1->getElemento(i, j) + mat2->getElemento(i, j), i, j);
                }
            }

            resultado.compativel = true;
            resultado.matriz = mat1;
        }
        return resultado;
    }

    ~Somador() {
    }
};

int main() {
    // Criação de duas matrizes 2x2
    Matriz* mat1 = new Matriz(2, 2);
    Matriz* mat2 = new Matriz(2, 2);

    // Definindo valores para a primeira matriz
    mat1->setElemento(1.0, 0, 0);
    mat1->setElemento(2.0, 0, 1);
    mat1->setElemento(3.0, 1, 0);
    mat1->setElemento(4.0, 1, 1);

    // Definindo valores para a segunda matriz
    mat2->setElemento(5.0, 0, 0);
    mat2->setElemento(6.0, 0, 1);
    mat2->setElemento(7.0, 1, 0);
    mat2->setElemento(8.0, 1, 1);
    

    Somador somador(mat1, mat2);

    Somador::res_soma resultado = somador.somar();

    if (resultado.compativel) {
        cout << "Matrizes somadas com sucesso!" << endl;
        for (int i = 0; i < resultado.matriz->linhas; i++) {
            for (int j = 0; j < resultado.matriz->colunas; j++) {
                cout << resultado.matriz->getElemento(i, j) << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Falha na soma das matrizes!" << endl;
    }

}
