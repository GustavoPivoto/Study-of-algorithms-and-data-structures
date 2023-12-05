#include <iostream>
#include <cstring>

using namespace std;

struct dados
{
    char nome[100];
    char curso[50];
    int matricula;
};

int pesquisa(char busca[], int N, dados aluno[])
{
    int i;
    int posicao;

    bool encontrado;

    for (i = 0; i < N; i++)
    {
        if (strcmp(busca, aluno[i].nome) == 0)
        {
            encontrado = true;
            posicao = i;
        }
    }
    if (encontrado == true)
        return posicao;
    else
        return -1;
}

int main()
{

    int N;
    int i;
    char busca[100];
    int valor;
    dados aluno[10000];

    cout << "Digite o numero de alunos: " << endl;
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin.ignore();
        cout << "Digite o nome: " << endl;
        cin.getline(aluno[i].nome, 100);
        cout << "Digite o curso: " << endl;
        cin.getline(aluno[i].curso, 100);
        cout << "Digite a matricula: " << endl;
        cin >> aluno[i].matricula;
    }
    cin.ignore();
    cout << "Digite a busca: " << endl;
    cin.getline(busca, 100);

    valor = pesquisa(busca, N, aluno);

    if (valor == -1)
        cout << "Aluno nao localizado" << endl;
    else
        for (i = 0; i < N; i++)
        {
            if (valor == i)
            {
                cout << aluno[i].nome << endl;
                cout << aluno[i].curso << endl;
                cout << aluno[i].matricula << endl;
                break;
            }
        }
    return 0;
}