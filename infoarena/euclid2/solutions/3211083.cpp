#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main ()
{
    int numar_teste;
    for (cin >> numar_teste ; numar_teste-- ; )
    {
        int valoare_1 , valoare_2;
        cin >> valoare_1 >> valoare_2;
        cout << __gcd(valoare_1 , valoare_2) << '\n';
    }

    cout.close(); cin.close();
    return 0;
}