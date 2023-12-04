#include <iostream>
#include <cstring>

using namespace std;

struct dado
{
    char info[50]; // informacao
    int k;         // chave
    int status;    // 0: vazio, 1:ocupado, 2:removido
};

int calcula_chave(char info[])
{
    int tam; // comprimento de nome
    int i;   // contador
    int k = 0;
    tam = strlen(info);
    for (i = 0; i < tam; i++)
        k += (int)info[i];
    return k;
}

int h1(int k, int m)
{
    int result;

    result = (k % m);
    if (result < 0)
        result += m;

    return result;
}

int h2(int k, int m)
{
    int result;

    result = (k % (m - 1));
    if (result < 0)
        result += m;

    return 1 + result;
}

int dhash(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % m;
}

int hash_insert(dado t[], int m, int k, char aux[])
{
    int j;
    int i = 0;

    do
    {
        j = dhash(k, m, i);
        if (t[j].status != 1)
        {
            t[j].k = k;

            t[j].status = 1;
            strcpy(t[j].info, aux);
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int hash_search(dado t[], int m, int k)
{
    int i = 0;
    int j;
    do
    {
        j = dhash(k, m, i);
        if (t[j].k == k)
            return j;
        i = i + 1;
    } while (t[j].status != 0 && i < m);
    return -1;
}

int hash_remove(dado t[], int m, int k)
{
    int j;

    j = hash_search(t, m, k);
    if (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;
        strcpy(t[j].info, "vazio");
        return 0; // consegui remover
    }
    else
        return -1; // k nao esta na tabela
}

int main()
{
    int k;
    int m;
    int i;
    int opcao;
    int r;
    char aux[100];
    dado t[100]; // tam hash

    cin >> m;

    // inicializando a tabela
    for (i = 0; i < m; i++)
    {
        t[i].k = -1;
        strcpy(t[i].info, "vazio");
        t[i].status = 0;
    }

    do
    {
        cin >> opcao;
        if (opcao > 0 && opcao < 5)
        {
            switch (opcao)
            {

            case 1:
                cin.ignore();
                cin.getline(aux, 50);
                k = calcula_chave(aux);
                hash_insert(t, m, k, aux);
                break;
            case 2:
                cin.ignore();
                cin.getline(aux, 50);
                k = calcula_chave(aux);
                r = hash_search(t, m, k);
                // imprimi chave não encontrado caso retorne -1
                if (r == -1)
                    cout << aux << " nao encontrado" << endl;
                else
                    cout << t[r].info << " encontrado na posicao " << r << endl;
                break;
            case 3:
                cin.ignore();
                cin.getline(aux, 50);
                k = calcula_chave(aux);
                hash_remove(t, m, k);
                break;

            case 4:
                for (i = 0; i < m; i++)
                    cout << t[i].info << endl;
                break;
            case 5:
                break;
            }
        }

    } while (opcao != 5);

    return 0;
}