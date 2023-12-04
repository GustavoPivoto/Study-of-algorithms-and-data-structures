#include <iostream>

using namespace std;

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

int main()
{
    int k, m, i;

    cin >> k >> m;

    for (i = 0; i < m; i++)
    {
        cout << dhash(k, m, i) << " " << endl;
    }
}