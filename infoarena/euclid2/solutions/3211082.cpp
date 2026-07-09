#include <fstream>
using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int Cmmdc (int valoare_1 , int valoare_2)
{
    int exponent = 0;
    while (!(valoare_1 & 1) && !(valoare_2 & 1))
        { valoare_1 >>= 1; valoare_2 >>= 1; exponent++; }

    while (valoare_1)
    {
        while (!(valoare_1 & 1))
            { valoare_1 >>= 1; }

        if (valoare_1 < valoare_2)
            { swap(valoare_1 , valoare_2); }

        valoare_1 -= valoare_2;
    }

    return valoare_2 << exponent;
}

int main ()
{
    int numar_teste;
    for (cin >> numar_teste ; numar_teste-- ; )
    {
        int valoare_1 , valoare_2;
        cin >> valoare_1 >> valoare_2;
        cout << Cmmdc(valoare_1 , valoare_2) << '\n';
    }

    cout.close(); cin.close();
    return 0;
}