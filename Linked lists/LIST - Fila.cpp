#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> fila;

    // Leitura e inserção dos valores na fila
    for (int i = 0; i < 4; ++i)
    {
        int valor;
        cin >> valor;
        fila.push_back(valor);
    }

    // Remoção e impressão dos elementos da fila
    while (!fila.empty())
    {
        cout << fila.front() << " "; // Mostra o primeiro elemento
        fila.pop_front();            // Remove o primeiro elemento
    }

    cout << endl;

    return 0;
}