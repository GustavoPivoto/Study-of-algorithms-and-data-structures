#include <iostream>

using namespace std;

int sequencial(int vetor[], int x, int aux)
{
    int i;
    int pos;
    bool res;

    res = false;
    for (i = 0; i < aux; i++)
    {
        if (x == vetor[i])
        {
            pos = i;
            res = true;
        }
    }
    if (res == false)
        return -1;
    else
        return pos;
}

int main()
{

    int aux = 0;
    int vetor[100];
    int valor;
    int x;
    int pos;

    do
    {
        cin >> valor;
        if (valor != -1)
        {
            vetor[aux] = valor;
            aux++;
        }
    } while (valor != -1);

    cin >> x;

    pos = sequencial(vetor, x, aux);

    if (pos == -1)
        cout << x << " nao encontrado" << endl;
    else
    {
        cout << x << " encontrado na posicao " << pos << endl;
    }
    return 0;
}