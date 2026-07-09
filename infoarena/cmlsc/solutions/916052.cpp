#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int n, m, a[1030], b[1030], c[1030][1030];
bool aux[1030][1030];

void LCS(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j]) {
                    c[i][j] = c[i-1][j-1] + 1;
                    aux[i][j] = true;
            }
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
}

void Afisare(int i, int j){
    if(i==0 || j==0) return ;
    if(aux[i][j] == true){
        Afisare(i-1, j-1);
        fout<<a[i]<<" ";
    }
    else if(c[i][j] == c[i-1][j]) Afisare(i-1, j);
    else Afisare(i, j-1);
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    LCS();
    fout<<c[n][m]<<'\n';
    Afisare(n, m);
    return 0;
}
