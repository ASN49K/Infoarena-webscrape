#include <fstream>

using namespace std;

long long gcd(long long x, long long y)
{/* Functia calculeaza cel  mai mare divizor comun dintre x si y
Date de intrare: x,y -> numere naturale nenule
Date de iesire: Returneaza cmmdc(x,y)
*/

/*Algoritmul se bazeaza pe resturi*/
    int rest;
    while(y>0)
    {
        rest = x%y;
        x = y;
        y = rest;
    }

    return x;
}

void solve()
{ifstream in("euclid2.in");
ofstream out("euclid2.out");

    int nT;/*numarul de teste*/
    in>>nT;

    for(int i=0; i<nT; i++)
    {
        long long x,y;
        in>>x>>y;

        out<<gcd(x,y)<<'\n';
    }

in.close();
out.close();
}
int main()
{
    solve();
    return 0;
}
