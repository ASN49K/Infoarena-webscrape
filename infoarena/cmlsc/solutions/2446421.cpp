#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define nmax 1024
int n,m,a[nmax][nmax],x[nmax],y[nmax],sir[nmax];
int main()
{int i,j;
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>x[i];
    for(int i=1;i<=n;i++)
        f>>y[i];
    //pentru a obtine solutia
    /*
    folosim tehnica programarii dinamice
    construim o matrice in felul urmator:
    daca elementele sunt egale elementul a[i,j]
    va lua valoarea elementului a[i-1,j-1]+1,
    altfel i se va atribui valoarea maxima dintre
    a[i-1,j] si a[i, j-1]
    */
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(x[i]==y[j])
        a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    */
    int k=0;
    for (i = m, j = n; i; )
        if (x[i] == y[j])
            sir[++k] = x[i], --i, --j;
        else if (a[i-1][j] < a[i][j-1])
            --j;
        else
            --i;
    g<<a[m][n]<<'\n';
    //cout<<k<<'\n';
    for (i = k; i; --i)
        g<<sir[i]<<" ";

    return 0;
}
