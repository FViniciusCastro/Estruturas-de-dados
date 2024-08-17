#include <exception>
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

    int getLinhas() const {
        return linhas;
    }

    int getColunas() const {
        return colunas;
    }

    void setElemento(double elem, int l, int c) {
        M[l][c] = elem;
    }

    double getElemento(int l, int c) const {
        return M[l][c];
    }

    ~Matriz() {
        for(int i = 0; i < linhas; i++) {
            delete[] M[i];
        }
        delete[] M;
    }
};

class Transpositor {

    Matriz* matriz;

public: 

    Transpositor(Matriz* m) {
        matriz = m;
    }

    Matriz* transpor() {

        Matriz* novaMatriz = new Matriz{matriz->getColunas(), matriz->getLinhas()};
        for(int i = 0; i < matriz->getLinhas(); i++){
            for(int j = 0; j < matriz->getColunas(); j++){ 
                novaMatriz->setElemento(matriz->getElemento(i, j), j, i);
            }
        }
        return novaMatriz;
    }

    ~Transpositor() {
    
    }

};

int main() {
    
    try {

        Matriz* mat = new Matriz(2, 3);
        mat->setElemento(1, 0, 0);
        mat->setElemento(2, 0, 1);
        mat->setElemento(3, 0, 2);
        mat->setElemento(4, 1, 0);
        mat->setElemento(5, 1, 1);
        mat->setElemento(6, 1, 2);

        cout << "Matriz original:" << endl;
        for (int i = 0; i < mat->getLinhas(); i++) {
            for (int j = 0; j < mat->getColunas(); j++) {
                cout << mat->getElemento(i, j) << " ";
            }
            cout << endl;
        }

        Transpositor transpositor(mat);
        Matriz* matTransposta = transpositor.transpor();


        cout << "Matriz transposta:" << endl;
        for (int i = 0; i < matTransposta->getLinhas(); i++) {
            for (int j = 0; j < matTransposta->getColunas(); j++) {
                cout << matTransposta->getElemento(i, j) << " ";
            }
            cout << endl;
        }

    } catch(const exception &e) {
        cerr << "EXCEÇÃO: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
