#include <bits/stdc++.h>
#define Nmax
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector < int > v1, v2, sol;

int n, m, lng;

void citire() ;
void afisare();

int main()
{
    citire ();

    int x = 0;

    for ( int i = 0; i < n; i++ )
        for ( int j = x; j < m; j++ )
            if  ( v1[i] == v2[j] )
            {
                sol.push_back(v1[i]);

                x = j+1;
                lng ++;
            }

    afisare () ;

}

void afisare()
{
    fout << lng << '\n';

    for ( int i = 0; i <sol.size() ; i++ )
        fout << sol[i]<< ' ';
}

void citire()
{
    int x;

    fin >> n >> m;

    for ( int i = 1; i <= n; i++ )
    {
        fin >> x;
        v1.push_back(x);
    }

    for ( int i = 1; i <= m; i++ )
    {
        fin >> x;
        v2.push_back(x);
    }
}
