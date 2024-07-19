// inversor de strings via pilha (usando biblioteca)
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<string> pilha;

    cout << "digite linhas terminando com linha vazia\n\n";

    for(;;){

        string linha; getline(cin,linha);

        if(linha == "") break;

        pilha.push(linha);

    }

    cout << "\nlinhas ordem inversa\n";

    while(not pilha.empty()){
        cout << pilha.top() << "\n";
        pilha.pop();
    }
}