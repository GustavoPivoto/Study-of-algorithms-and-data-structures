#include <iostream>

using namespace std;

// Retorna a posição emque X foi encontrado no vetor
// Retorna -1 se X não for encontrado
int binaria(int vetor[], int tamanho, int x)
{
    bool achou;            // var aux p/ busca
    int baixo, meio, alto; // var aux
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
    if (achou) // se achou for verdadeiro o comando vai rodar
        return meio;
    else
        return -1;
}

int main()
{
    int N;
    int i;
    int x;
    int num[10000];
    int pos; // posição

    // 1 - Ler N
    cout << "Insira o numero de  valores:" << endl;
    cin >> N;

    // 2 - Ler N elementos e armazenar no vetor
    cout << "Insira os valores" << endl;
    for (i = 0; i < N; i++)
        cin >> num[i];

    // 3 - buscando e elemento x a ser encontrado
    cout << "Buscar: " << endl;
    cin >> x;

    // 4 - procurando X no vetor
    pos = binaria(num, x, N);

    if (pos == -1)
        cout << "Não encontrado" << endl;
    else
        cout << "Valor encontrado na posicao: " << pos << endl;

    return 0;
}