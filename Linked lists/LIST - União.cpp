#include <iostream>
#include <list>
using namespace std;

// função bool para verificar a existencia de elementos iguais
bool busca(list<int> lista, int x)
{

    list<int>::iterator p;

    for (p = lista.begin(); p != lista.end(); p++)
        if (*p == x)
            return true;

    return false;
}
int main()
{
    list<int> lista1, lista2, lista3; // declaradno as treês listas de ponteiros
    list<int>::iterator p;            // ponteiro para varrer as listas

    int x; // variavel para leitura dos valores
    do
    {
        cin >> x; // lendo valores
        // verificando condição
        if (x != 0)
            // adiciona o elemento x na lista
            lista1.push_back(x);

    } while (x != 0);

    do
    {
        cin >> x; // lendo valores
        // verificando condição
        if (x != 0)
            // adiciona o elemento x na lista
            lista2.push_back(x);

    } while (x != 0);

    // unindo as duas listas
    for (p = lista1.begin(); p != lista1.end(); p++)
        lista2.push_back(*p);
    for (p = lista2.begin(); p != lista2.end(); p++)
    {
        if (!busca(lista3, *p)) // verifica se tem valores iguais e então insere na lista
            lista3.push_back(*p);
    }

    lista3.sort(); // reordena a lista

    // imprime a lista reordenada
    for (p = lista3.begin(); p != lista3.end(); p++)
        cout << *p << " ";

    // liberando a memoria alocada
    while (!lista1.empty() && !lista2.empty() && lista3.empty())
    {
        // remove o primeiro elemento da lista
        lista1.pop_front();
        lista2.pop_front();
        lista3.pop_front();
    }

    return 0;
}