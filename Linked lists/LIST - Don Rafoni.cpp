#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string nome;
    float valor;
    Node *proximo;
};

void adicionarDevedor(Node*& lista, string nome, float valor) {
    Node* novoDevedor = new Node;
    novoDevedor->nome = nome;
    novoDevedor->valor = valor;
    novoDevedor->proximo = nullptr;

    if (lista == nullptr) {
        lista = novoDevedor;
    } else {
        Node* atual = lista;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novoDevedor;
    }
}

void quitarDivida(Node*& lista, string nome) {
    Node* atual = lista;
    Node* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->nome == nome) {
            Node* temp = atual;
            if (anterior != nullptr) {
                anterior->proximo = atual->proximo;
                atual = atual->proximo;
            } else {
                lista = atual->proximo;
                atual = lista;
            }
            delete temp;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
    adicionarDevedor(lista, nome, 0);
}

void exibirLista(Node *lista)
{
    Node *atual = lista;
    while (atual != nullptr)
    {
        if(atual->valor != 0){
            cout << atual->nome << endl;
            cout << atual->valor << endl;
        }
        atual = atual->proximo;
    }
}

int main()
{
    int quantidadeDevedores;
    cin >> quantidadeDevedores;

    Node *listaDevedores = nullptr;

    for (int i = 0; i < quantidadeDevedores; ++i)
    {
        string nome;
        float valor;
        cin.ignore();
        getline(cin, nome);
        cin >> valor;

        adicionarDevedor(listaDevedores, nome, valor);
    }

    string nomeQuitado;
    cin.ignore();
    getline(cin, nomeQuitado);

    quitarDivida(listaDevedores, nomeQuitado);

    exibirLista(listaDevedores);

    while (listaDevedores != nullptr)
    {
        Node *temp = listaDevedores;
        listaDevedores = listaDevedores->proximo;
        delete temp;
    }

    return 0;
}