#include <fstream>
using namespace std;

ifstream cin ("nim.in");
ofstream cout ("nim.out");

int main ()
{
    uint16_t numar_teste;
    for (cin >> numar_teste ; numar_teste-- ; )
    {
        uint16_t lungime;
        uint32_t suma_xor = 0;
        for (cin >> lungime ; lungime-- ; ) 
            { uint32_t valoare; cin >> valoare; suma_xor ^= valoare; }

        cout << (suma_xor ? "DA\n" : "NU\n");
    }

    cout.close(); cin.close();
    return 0;
}