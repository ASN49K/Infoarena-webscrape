#include<fstream.h>

#define nmax 1100

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j, a[nmax], b[nmax], d[nmax][nmax], nr, sol[nmax];

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++) f>>a[i];
    for(j=1; j<=m; j++) f>>b[j];
    f.close();
    
    for(i=1; i<=n; i++) 
        for(j=1; j<=m; j++) 
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else if( d[i-1][j] > d[i][j-1] ) d[i][j]=d[i-1][j];
                        else d[i][j]=d[i][j-1];

    for(i=n, j=m; j ; )
        if(a[i]==b[j]) sol[++nr]=a[i], i--, j--;
            else if( d[i-1][j] < d[i][j-1] ) j--;
                    else i--;

    g<<nr<<'\n';
    for(i=nr; i>0; i--) g<<sol[i]<<' ';

    g.close();
    return 0;
}
