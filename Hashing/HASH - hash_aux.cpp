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

int main()
{

    int k;
    int m;

    do
    {
        cin >> k;
        cin >> m;
        if (k != 0 && m != 0)
            cout << hash_aux(k, m) << endl;
    } while (k != 0 && m != 0);

    return 0;
}