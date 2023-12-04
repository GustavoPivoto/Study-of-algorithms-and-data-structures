#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

bool encontrar(list<int> lista, int x)
{
    list<int>::iterator p; // ponterio p/ andar na lista
    for (p = lista.begin(); p != lista.end(); p++)
    {
        if (*p == x)
            return 0;
    }
    return 1;
}

int main()
{
    // fila o primeiro que entra é o primeiro que sai
    list<int> fila; // ponteiro pra lista

    int i; // contador
    int x; // var aux leitura e escrita
    int busca;
    int res;
    // lendo elementos e inserindo-os na fila
    for (i = 0; i < 4; i++)
    {
        cin >> x;
        fila.push_back(x); // insere x no final da fila
    }

    cin >> busca; // lê o valor a ser encontrado na fila

    res = encontrar(fila, busca);

    if (res == 0)
        cout << "Encontrado" << endl;
    else
        cout << "Nao encontrado" << endl;

    // liberando a memoria alocada pela lista ligada
    while (!fila.empty())
        fila.pop_front(); // remove o primeiro elemento da lista

    return 0;
}