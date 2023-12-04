#include <iostream>
#include <iomanip> // Adicionado para manipulação de saída de ponto flutuante
#include <cstring>

using namespace std;

struct info
{
    char nome[100];
    int idade;
    float peso;
    float altura;
};

struct dado
{
    info atleta;
    int k;      // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
};

int h1(char *nome, int m)
{
    int result = 0;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        result += nome[i];
    }
    return result % m;
}

int h2(char *nome, int m)
{
    int result;
    result = h1(nome, m - 1);
    if (result < 0)
        result += m;

    return result + 1;
}

int dhash(char *nome, int m, int i)
{
    return (h1(nome, m) + i * h2(nome, m)) % m;
}

int hash_insert(dado t[], int m, info &atleta)
{
    int i = 0;
    int j;
    do
    {
        j = dhash(atleta.nome, m, i);
        if (t[j].status != 1)
        {
            t[j].atleta = atleta;
            t[j].k = h1(atleta.nome, m);
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int hash_search(dado t[], int m, char *nome)
{
    int j;
    int i = 0;

    do
    {
        j = dhash(nome, m, i);
        if (t[j].status == 0)
            return -1; // atleta não encontrado
        if (strcmp(t[j].atleta.nome, nome) == 0 && t[j].status == 1)
            return j;
        i = i + 1;
    } while (i < m);
    return -1;
}

int hash_remove(dado t[], int m, char *nome)
{
    int j;
    int i = 0;

    do
    {
        j = dhash(nome, m, i);
        if (t[j].status == 0)
            return -1; // atleta não encontrado
        if (strcmp(t[j].atleta.nome, nome) == 0 && t[j].status == 1)
        {
            t[j].status = 2; // marcando como removido
            return 0;        // conseguiu remover
        }
        i = i + 1;
    } while (i < m);
    return -1;
}

void print_atleta(info &atleta)
{
    cout << "Nome: " << atleta.nome << endl;
    cout << "Idade: " << atleta.idade << endl;
    cout << "Peso: " << fixed << setprecision(1) << atleta.peso << endl;
    cout << "Altura: " << fixed << setprecision(2) << atleta.altura << endl;
}

int main()
{
    int m;
    int opcao;

    dado t[100];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        t[i].status = 0;
    }

    do
    {
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            info novo_atleta;
            cin.ignore(); // para consumir a quebra de linha pendente
            cin.getline(novo_atleta.nome, sizeof(novo_atleta.nome));
            cin >> novo_atleta.idade >> novo_atleta.peso >> novo_atleta.altura;
            hash_insert(t, m, novo_atleta);
            break;
        }
        case 2:
        {
            char nome[100];
            cin.ignore(); // para consumir a quebra de linha pendente
            cin.getline(nome, sizeof(nome));
            int index = hash_search(t, m, nome);
            if (index != -1)
                print_atleta(t[index].atleta);
            else
                cout << endl
                     << nome << " nao encontrado" << endl
                     << endl;
            break;
        }
        case 3:
        {
            char nome[100];
            cin.ignore(); // para consumir a quebra de linha pendente
            cin.getline(nome, sizeof(nome));
            hash_remove(t, m, nome);
            break;
        }
        case 4:
            for (int i = 0; i < m; i++)
            {
                if (t[i].status == 1)
                {
                    print_atleta(t[i].atleta);
                    cout << endl;
                }
            }
            break;
        }
    } while (opcao != 5);

    return 0;
}
