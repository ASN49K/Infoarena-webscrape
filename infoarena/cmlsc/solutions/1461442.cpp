#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main()
{
    int n, m;
    fin >> n >> m;

    int a[n+1], b[m+1], mx[n+1][m+1], c[n+m], k=0;

    for(int i=1; i<=n; i++){
        fin >> a[i];
    }
    for(int i=1; i<=m; i++){
        fin >> b[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(a[i] == b[j]){
                mx[i][j] = mx[i-1][j-1] + 1;
                c[k] = a[i];
                k++;
            }
            else if(a[i] != b[j] && i > 0 && j > 0) mx[i][j] = max(mx[i][j-1], mx[i-1][j]);
            else mx[i][j] = 0;
        }
    }

    fout<<mx[n][m]<<"\n";
    for(int i=0; i<k; i++){
        fout<<c[i]<<" ";
    }
    return 0;
}
