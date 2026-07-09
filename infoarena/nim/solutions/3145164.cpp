#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int n, gramezi, x;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> gramezi;
        int suma_xor = 0;
        for(int j = 1; j <= gramezi; j++)
        {
            cin >> x;
            suma_xor = suma_xor ^ x;
        }
        if(suma_xor > 0)
            cout << "DA\n";
        else
            cout << "NU\n";
    }

    return 0;
}
