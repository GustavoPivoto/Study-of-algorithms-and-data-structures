#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->info = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(int x, int y)
    {
        Node *current = head;
        while (current != nullptr && current->info != x)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            Node *newNode = new Node;
            newNode->info = y;
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void pop()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void printList() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList lista;

    int valor;
    while (true)
    {
        cin >> valor;
        if (valor == -1)
            break;
        lista.push(valor);
    }

    int x, y;
    cin >> x >> y;

    lista.insertAfter(x, y);

    while (!lista.isEmpty())
    {
        lista.printList();
        lista.pop();
    }

    return 0;
}
