#include <iostream>

using namespace std;

int binaria(int vetor[], int tamanho, int x)
{
    bool achou;
    int baixo;
    int meio;
    int alto;

    baixo = 0;
    alto = tamanho - 1;
    achou = false;

    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2;
        if (x < vetor[meio])
            alto = meio - 1;
        else if (x > vetor[meio])
            baixo = meio + 1;
        else
            achou = true;
    }
    if (achou)
        return meio;
    else
        return -1;
}

int main()
{
    int valor;
    int vetor[20];
    int tamanho = 0;
    int x;
    int acesso;

    do
    {
        cin >> valor;
        if (valor != -1)
        {
            vetor[tamanho] = valor;
            tamanho++;
        }

    } while (valor != -1);

    cin >> x;

    acesso = binaria(vetor, tamanho, x);

    if (acesso == -1)
        cout << "Nao possui acesso " << endl;
    else
    {
        cout << "Possui acesso" << endl;
    }
    return 0;
}