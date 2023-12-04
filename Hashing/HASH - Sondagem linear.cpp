#include <iostream>

using namespace std;

int hash_aux(int k, int m)
{
    int result;
    result = k % m;
    if (result < 0)
        result += m;

    return result;
}

int hash1(int k, int i, int m)
{
    return (hash_aux(k, m) + i) % m;
}

int main()
{

    int k;
    int m;
    int i;

    cin >> k;
    cin >> m;

    for (i = 0; i < m; i++)
        cout << hash1(k, i, m) << " " << endl;

    return 0;
}