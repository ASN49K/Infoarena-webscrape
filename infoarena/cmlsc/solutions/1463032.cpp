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
            if(a[i] == b[j]) mx[i][j] = mx[i-1][j-1] + 1;
            else if(a[i] != b[j]) mx[i][j] = max(mx[i][j-1], mx[i-1][j]);
        }
    }

    fout<<mx[n][m]<<"\n";

    int i=n, j=m;
    while(i){
            if(a[i] == b[j] && k == 0){
                c[k][0] = a[i];
                c[k][1] = b[j];
                k++;
                j--;
                i--;
            }else if(k>0 && a[i]==b[j] && a[i] < c[k-1][0] && b[j] < c[k-1][1]){
                c[k][0] = a[i];
                c[k][1] = b[j];
                k++;
                j--;
                i--;
            }else if(a[i] != b[j] && mx[i][j-1] == mx[i-1][j]) j--;
                else if(a[i] != b[j] && mx[i][j-1] > mx[i-1][j]) j--;
                    else if(a[i] != b[j] && mx[i][j-1] < mx[i-1][j]) i--;
    }

    for(i=k-1; i>=0; i--){
        fout<<c[i][0]<<" ";
    }
    return 0;
}
