#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] < chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
}
int main()
{
    int num;
    int vetor[10000];
    int auxt = 0;
    int tamanho;
    int i;

    do
    {
        cout << "Digite um valor: " << endl;
        cin >> num;
        if (num != 0)
        {
            vetor[auxt] = num;
            auxt++;
        }
    } while (num != 0);

    tamanho = auxt;

    insercaoDireta(vetor, tamanho);

    for (i = 0; i < tamanho; i++)
        cout << vetor[i] << " ";

    return 0;
}