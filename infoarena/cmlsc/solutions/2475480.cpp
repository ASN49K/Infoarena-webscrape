#include <bits/stdc++.h>
#define Nmax 1026
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[ Nmax ][ Nmax ];

int n,m, maxim;

vector < int >  v1, v2, sol;

void citesc ();
void process();
void afisare ();

int main()
{
    citesc();
    process();
    afisare();
}

void process()
{
    int i1,j1;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            if ( v1[i-1] == v2[j-1] )
            {
                a[i][j] = a[i-1][j-1]+1;
                if ( a[i][j] > maxim )
                    maxim = a[i][j], i1 = i, j1 = j;
            }
            else
                a[i][j]= max (a[i-1][j],a[i][j-1]);
        }

    while ( i1 && j1 )
    {
        if ( v1[i1-1] != v2[j1-1])
            if ( a[i1-1][j1] > a[i1][j1-1])
                i1--;
            else
               j1--;
        else sol.push_back(v1[i1-1]),i1--,j1--;
    }

   // if(v1[i1-1] == v2[j1-1] )sol.push_back(v1[i1-1]);
}

void citesc ()
{
    int x;

    fin >> n >> m;

    v1.reserve ( n+2 );
    v2.reserve ( m+2 );

    sol.reserve( min(n,m) + 2 );

    for  ( int i = 0; i < n; i++ )
    {
        fin >> x;

        v1.push_back(x);
    }

    for  ( int i = 0; i < m; i++ )
    {
        fin >> x;

        v2.push_back(x);
    }

    fin.close();
}

void afisare ()
{
    fout << maxim << '\n';

    int lng = sol.size();

    for ( int i = lng-1; i >= 0; i-- )
        fout << int (sol[i]) << ' ';

    fout.close();
}
