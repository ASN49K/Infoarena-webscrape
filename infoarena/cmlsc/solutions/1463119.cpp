#include <iostream>
#include <fstream>
#define nmax 1030

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[nmax], b[nmax], mx[nmax][nmax], c[nmax*2], k;

int main()
{
    ///Citire
    fin >> n >> m;

    for(int i=1; i<=n; i++){
        fin >> a[i];
    }
    for(int i=1; i<=m; i++){
        fin >> b[i];
    }

    ///Creare matrice
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j])
                mx[i][j] = mx[i-1][j-1] + 1;
            else if(a[i] != b[j]) mx[i][j] = max(mx[i][j-1], mx[i-1][j]);
        }
    }
    int i,j;
    i=n;j=m;k=mx[n][m];
    fout<<k<<"\n";
    while(i&&j&&mx[i][j])
        if(a[i]==b[j])
            {c[--k]=a[i];i--;j--;}
        else
            if(mx[i][j]==mx[i-1][j])i--;
            else j--;
    k=mx[n][m];
    for(int i=0; i<k; i++){
        fout<<c[i]<<" ";
    }
    return 0;
}
