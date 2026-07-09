#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int n, gramezi, x;

void base2(int n, int nr[], int &nr_cifre)
{
    int cn = n;
    nr_cifre = 0;
    while(cn)
    {
        nr_cifre++;
        cn/=2;
    }
    for(int i = nr_cifre; i >= 1; i--)
    {
        nr[i] = n % 2;
        n = n/2;
    }

}

void sum_xor(int a[], int b[], int maxim)
{
    for(int i = 1; i <= maxim; i++)
    {
        if((a[i] == 0 && b[i] == 0) || (a[i] == 1 && b[i] == 1))
            a[i] = 0;
        else
            a[i] = 1;
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> gramezi;
        int suma_xor[1005] = {0};
        int nr[1005] = {0}, nrcifre = 0;
        int maxim = 0;
        for(int j = 1; j <= gramezi; j++)
        {
            cin >> x;
            base2(x, nr, nrcifre);
            if(maxim < nrcifre)
                maxim = nrcifre;
            sum_xor(suma_xor, nr, maxim);
        }
        int suma = 0;
        for(int i = 1; i <= maxim; i++)
            suma+=suma_xor[i];
        if(suma > 0)
            cout << "DA\n";
        else
            cout << "NU\n";
    }

    return 0;
}
