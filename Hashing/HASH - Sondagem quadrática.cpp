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

int hash2(int k, int i, int m, int c1, int c2)
{
    return (hash_aux(k, m) + c1 * i + c2 * i * i) % m;
}
int main()
{

    int k, m, i, c1, c2;

    cin >> k >> m >> c1 >> c2;

    for (i = 0; i < m; i++)
    
        cout << hash2(k, i, m, c1, c2) << " " << endl;

    return 0;
}