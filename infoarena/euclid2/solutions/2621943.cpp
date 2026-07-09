#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, r, n;
int main()
{
    fin >> n;
    for (int i = 1; i <= n; i ++)
    {
        fin >> a >> b;
        if (a < b)
        {
            int aux = a;
            a = b;
            b = aux;
        }
        r = a % b;
        while (r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        fout << b << "\n";
    }
    return 0;
}
