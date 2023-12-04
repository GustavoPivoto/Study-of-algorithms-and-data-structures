#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista)
{
    list<int>::iterator p; // ponteiro pra andar na lista
    int soma = 0;          // variavel que armazena a soma dos nós
    // varrendo e somando os elementos da lista
    for (p = lista.begin(); p != lista.end(); p++)
    {
        soma += *p;
    }
    return soma; // retornando o valor da soma
}

int main()
{
    list<int> fila; // declarando a fila

    int x; // variavel pra leitura
    // faça enquanto x for diferente de zero
    do
    {
        cin >> x; // lendo x
        // verificando condição
        if (x != 0)
        {
            // inserindo na lista
            fila.push_back(x);
        }
    } while (x != 0);

    // imprimindo a soma dos nós
    cout << soma(fila) << endl;

    // liberando a memoria alocada pela lista ligada
    while (!fila.empty())
        fila.pop_front(); // remove o primeiro elemento da lista

    return 0;
}