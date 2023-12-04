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
        if (t[j].k == k && t[j].status == 1)
            return j;
        i = i + 1;
    } while ((t[j].status != 0) && (i < m));
    return -1;
}

int hash_remove(dado t[], int m, int k)
{
    int j = hash_search(t, m, k);
    if (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;
        return 0; // conseguiu remover
    }
    else
        return -1; // k não está na tabela
}

void print_table(dado t[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << t[i].k;
        if (i < m - 1)
            cout << " ";
    }
}

int main()
{
    int m;
    int k;

    cout << "Digite o tamanho da tabela: ";
    cin >> m;

    dado t[100];

    for (int i = 0; i < m; i++)
    {
        t[i].k = -1;
        t[i].status = 0;
    }

    cout << "Digite as chaves a serem inseridas (termine com 0): ";
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        hash_insert(t, m, k);
    }

    cout << "Digite a chave a ser removida: ";
    cin >> k;

    hash_remove(t, m, k);

    cout << "Tabela após a remoção: ";
    print_table(t, m);
    cout << endl;

    return 0;
}