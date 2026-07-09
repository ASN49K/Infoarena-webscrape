#include <iostream>
#include <fstream>
#include <iomanip>

#define FOR(i, k, v) for(i = k; i <= v; i++)
#define FOR2(i, k, v) for(i = k; i >= v; i--)
#define Nmax 1024
#define maxx(a, b) ((a > b) ? a : b )

using namespace std;

int i,j,n,m,a[Nmax],b[Nmax],t[Nmax][Nmax],megoldas[Nmax],q,q2;

int main()
{

    ifstream be("cmlsc.in");
    ofstream ki("cmlsc.out");
    be>>n>>m;

    FOR(i,1,n)
        be>>a[i];
    FOR(i,1,m)
        be>>b[i];

    FOR(i,1,n)
        FOR(j,1,m)
            if(a[i]==b[j])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = maxx(t[i-1][j],t[i][j-1]);

    ki<<t[n][m]<<endl;
    q = t[n][m];
    q2 = q;

    i = n;
    j = m;
    while(i > 0 and j > 0)
    {
        if(a[i] == b[j])
        {
            megoldas[q] = a[i];
            q--;
        }
        if(t[i-1][j] > t[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    if(megoldas[0]!=0)
    FOR(i,0,q2)
        ki<<megoldas[i]<<" ";
    else
    FOR(i,1,q2)
        ki<<megoldas[i]<<" ";


    return 0;
}
