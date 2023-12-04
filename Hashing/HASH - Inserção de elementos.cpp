#include <iostream>

using namespace std;

struct dado
{

    int k;      // chave
    int status; // 0: vazio, 1: ocupado
};

int hash_aux(int k, int m)
{
    int result;

    result = (k % m);
    if (result < 0)
        result += m;

    return result;
}

int hash1(int k, int i, int m)
{
    return ((hash_aux(k, m) + i) % m);
}

int hash_insert(dado t[], int m, int k)
{
    int j;
    int i = 0;

    do
    {
        j = hash1(k, i, m);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int main()
{
    dado t[100]; // tam hash
    int m;       // tam da tabela
    int i;       // contador
    int k;

    // lendo o tam da tabela
    cin >> m;

    // inicializando a tabela
    for (i = 0; i < m; i++)
    {
        t[i].k = -1;
        t[i].status = 0;
    }

    // lendo as chaves
    do
    {
        cin >> k;
        if (k != 0)
            hash_insert(t, m, k);

    } while (k != 0);

    for (i = 0; i < m; i++)
        cout << t[i].k << endl;

    return 0;
}