#include <iostream>
#include <fstream>

using namespace std;

#define max(a,b) ((a > b )? a : b)
#define Maxim 1024

int v[Maxim], w[Maxim],sir[Maxim], lsc[Maxim][Maxim] = {{0}}, m, n ;

void rezolva(int k, int l)
{
     int x,y;
     for (x=1; x<=k;x++)
         for (y=1; y<=l; y++)
         {   
                 if ( v[x] == w[y] ) lsc[x][y] = 1 + lsc[x-1][y-1];
                 else lsc[x][y] = max(lsc[x-1][y], lsc[x][y-1]);
         }
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n;
    f>>m>>n;
    int i,j,nr=0;
    for (i=1;i<=m;i++)
    f>>v[i];
    for (j=1;j<=n;j++)
    f>>w[j];
    rezolva (m,n);
    g<<lsc[m][n]<<"\n";
    for ( i = m, j = n; i > 0 && j > 0;)
    {
        if ( v[i] == w[j] && lsc[i][j] != 0 ) { 
                          sir[nr]=v[i];
                          nr++;
                          i--;
                          j--;}
        else { 
             if (lsc[i-1][j] > lsc[i][j-1]) i--;
             else j--;
             }
    }
    for (i= lsc[m][n]-1; i>=0;i--)
    {
        g<<sir[i]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
