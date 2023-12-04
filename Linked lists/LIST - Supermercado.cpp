#include <iostream>
#include <list>

using namespace std;

int main()
{
    // fila: o primeiro que entra é o primeiro que sai
    list<int> estoque;     // lista de ponteiro pra estoque
    list<int> venda;       // lista de ponteiro pra venda
    list<int>::iterator p; // ponteiro p/ andar na lista
    list<int>::iterator q; // ponteiro p/ andar na lista

    int N;     // numero de operações;
    int i;     // contador
    int x;     // armazena valor
    int opcao; // 1 adiciona em estoque, 2 tira de estoque e coloca em vendas

    cin >> N; // lendo o numero de operações

    for (i = 0; i < N; i++)
    {
        cin >> opcao; // lendo a opcao
        // verificando condições
        switch (opcao)
        {
        case 1:
            cin >> x;             // lendo o valor a ser armazenado estoque
            estoque.push_back(x); // coloca no final da fila
            break;
        default:
            p = estoque.begin();  // p recebe o inicio de estoque
            venda.push_front(*p); // coloca na fila de vendas o valor armazenado em *p
            estoque.pop_front();  // remove uma posição da fila de estoque
            break;
        }
    }
    cout << "Estoque: ";
    for (p = estoque.begin(); p != estoque.end(); p++)
    {
        // imprimindo os valores armazendados em estoque
        cout << *p << " ";
    }
    cout << endl;
    cout << "Venda: ";
    for (q = venda.begin(); q != venda.end(); q++)
    {
        // imprimindo os valores armazendados em venda
        cout << *q << " ";
    }
    cout << endl;
    // liberando a memoria alocada pela lista ligada
    while (!estoque.empty())
    {
        estoque.pop_front(); // remove o primeiro elemento da lista
    }
    while (!venda.empty())
    {
        venda.pop_front(); // remove o primeiro elemento da lista
    }

    return 0;
}