#include <iostream>

using namespace std;

struct dado
{
    int k;
    int status; // 0-vazio, 1-ocupado, 2-removido
};

int h1(int k, int m)
{
    int result;
    result = k % m;
    if (result < 0)
        result += m;
    return result;
}

int h2(int k, int m)
{
    int result;
    result = h1(k, m - 1);
    if (result < 0)
        result += m;

    return result + 1;
}

int dhash(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % m;
}

int hash_insert(dado t[], int m, int k)
{
    int i = 0;
    int j;
    do
    {
        j = dhash(k, m, i);
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

int hash_search(dado t[], int m, int k)
{
    int j;
    int i = 0;

    do
    {
        j = dhash(k, m, i);
        if (t[j].status == 0)
            return -1; // chave não encontrada
        if (t[j].k == k && t[j].status == 1)
            return j;
        i = i + 1;
    } while (i < m);
    return -1;
}

int hash_remove(dado t[], int m, int k)
{
    int j;
    int i = 0;

    do
    {
        j = dhash(k, m, i);
        if (t[j].status == 0)
            return -1; // chave não encontrada
        if (t[j].k == k && t[j].status == 1)
        {
            t[j].status = 2; // marcando como removido
            return 0;        // conseguiu remover
        }
        i = i + 1;
    } while (i < m);
    return -1;
}

int main()
{
    int k;
    int m;
    int opcao;

    dado t[100];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        t[i].k = -1;
        t[i].status = 0;
    }

    do
    {
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cin >> k;
            hash_insert(t, m, k);
            break;
        case 2:
            cin >> k;
            cout << hash_search(t, m, k) << endl;
            break;
        case 3:
            cin >> k;
            hash_remove(t, m, k);
            break;
        case 4:
            for (int i = 0; i < m; i++)
            {
                if (t[i].status == 1)
                    cout << t[i].k << " ";
                else
                    cout << -1 << " ";
            }
            cout << endl;
            break;
        }
    } while (opcao != 5);

    return 0;
}
