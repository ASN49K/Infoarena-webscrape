
#include<iostream>
#include<fstream>


#define MAX(a,b) (a > b) ? a : b
#define FOR(i,a,b) for(i = a; i<=b; ++i)
#define Nmax 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int *a, *b, D[Nmax][Nmax],i ,j ,n ,m;

int main()
{
    f>>m>>n;

    a = new int[m+1];
    b = new int[n+1];

    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];

    int  sir[Nmax], bst=0;

    FOR(i,0,m)
        FOR(j,0,n)
            D[i][j] = 0;

    FOR(i,1,m)
        FOR(j,1,n)
            if(a[i]==b[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = MAX(D[i-1][j],D[i][j-1]);


    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;//sir -> [1,n]
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    g<<bst<<endl;
       for (i = bst; i; --i)
           g<<sir[i]<<" ";

    return 0;
}
