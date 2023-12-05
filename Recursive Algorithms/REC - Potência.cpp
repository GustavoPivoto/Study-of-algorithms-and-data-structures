#include <iostream>
#include <cmath>

using namespace std;

int rec(int a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * rec(a, n - 1);
}

int main()
{
    int a;
    int n;

    cin >> a;
    cin >> n;

    cout << rec(a, n);
    return 0;
}