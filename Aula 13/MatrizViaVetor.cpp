// Matriz via um unico vetor
#include <iostream>
#include <exception>

using namespace std;

class Matriz {

    int linhas, colunas;
    double* V;

public:

    Matriz(int l, int c) {

        linhas = l;
        colunas = c;
        V = new double[l*c];
    }

    double getElemento(int l, int c) {
        return V[c + l*linhas];
    }

    void setElemento(double elem, int l, int c) {
        V[c + l*linhas] = elem;
    }

    int getLinhas() {return linhas;}
    int getColunas() {return colunas;}

    ~Matriz() {
        delete[] V;
    }
};

int main() {

    try {
       
        Matriz mat(2, 4);
        
        mat.setElemento(1.0, 0, 0);
        mat.setElemento(2.0, 0, 1);
        mat.setElemento(3.0, 0, 2);
        mat.setElemento(4.0, 0, 3);
        mat.setElemento(5.0, 1, 0);
        mat.setElemento(6.0, 1, 1);
        mat.setElemento(7.0, 1, 2);
        mat.setElemento(8.0, 1, 3);

        
        cout << "Matriz:" << endl;
        for (int i = 0; i < mat.getLinhas(); i++) {
            for (int j = 0; j < mat.getColunas(); j++) {
                cout << mat.getElemento(i, j) << " ";
            }
            cout << endl;
        }
    } catch(const exception &e) {
        cerr << "EXCEÇÃO" << e.what() << "\n";
        return 1;
    }

        return 0;
}