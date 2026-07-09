#include <iostream>
#include <fstream>
#define nmax 1024

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[nmax], b[nmax], mx[nmax][nmax], c[nmax*2][2], k;

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
            if(a[i] == b[j]){
                mx[i][j] = mx[i-1][j-1] + 1;
                c[k][0] = a[i];
                c[k][1] = b[j];
                k++;
            }
            else if(a[i] != b[j]) mx[i][j] = max(mx[i][j-1], mx[i-1][j]);
            //else mx[i][j] = 0;
        }
    }

    for(int i=0; i<k-1; i++){
        if(c[i][0] > c[i+1][0] || c[i][1] > c[i+1][1]) mx[n][m]--;
    }
    if(c[k-2][0] > c[k-1][0] || c[k-2][1] > c[k-1][1]) mx[n][m]--;
    fout<<mx[n][m]<<"\n";

     for(int i=0; i<k-1; i++){
        if(c[i][0] < c[i+1][0] && c[i][1] < c[i+1][1]) fout<<c[i][0]<<" ";
    }
    if(c[k-2][0] < c[k-1][0] && c[k-2][1] < c[k-1][1]) fout<<c[k-1][0];

    return 0;
}
