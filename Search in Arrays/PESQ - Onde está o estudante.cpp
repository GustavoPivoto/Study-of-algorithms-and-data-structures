#include <iostream>

using namespace std;

int localiza(int vetor[], int N, int x)
{
    int i;
    int corredor = -1;
    for (i = 0; i < N; i++)
    {
        if (x == vetor[i])
            corredor = i;
    }
    return corredor;
}
int main()
{
    int N;
    int vetor[10000];
    int matricula;
    int x;
    int i;
    int corredor;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> matricula;
        vetor[i] = matricula;
    }

    cin >> x;

    corredor = localiza(vetor, N, x);

    if (corredor == -1)
        cout << "Nao Localizado" << endl;
    else
        cout << "Corredor " << corredor << endl;
    return 0;
}