#include <iostream>
#include <list> // biblioteca para listas

using namespace std;

int main()
{
    //	pilha: o ultimo chega é o primeiro que sai
    list<int> pilha; // declarando a pilha p/ receber inteiros

    int x; // dado a ser inserido
    int i; // contador

    // inserindo dados na pilha
    for (i = 0; i < 4; i++)
    {
        cin >> x;
        pilha.push_front(x); // insere x no topo da pilha
    }

    // removendo e mostrando elementos da pilha
    while (!pilha.empty()) // enquanto a pilha não estiver no fim
    {
        x = *pilha.begin(); //*pilha.begin() = ponteiro que aponta para  o inicio da pilha
        cout << x << " ";
        pilha.pop_front(); // remove o ultimo do fim da pilha
    }

    return 0;
}