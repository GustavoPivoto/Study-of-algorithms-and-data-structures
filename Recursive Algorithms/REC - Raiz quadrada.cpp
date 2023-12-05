#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float raiz(float x, float xo, float e)
{
    float aux;
    aux = xo * xo - x;
    if (aux < 0)
        aux = aux * (-1);
    if (aux <= e)
        return xo;
    else
        return raiz(x, (xo * xo + x) / (2 * xo), e);
}

int main()
{

    float x, xo, e;

    cin >> x >> xo >> e;

    cout << fixed << setprecision(4) << raiz(x, xo, e) << endl;

    return 0;
}