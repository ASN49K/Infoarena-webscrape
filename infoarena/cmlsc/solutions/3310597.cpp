#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1030], b[1030], i, j,
    d[1030][1030], c[1030], p=1;

void citire()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
}

void dp()
{
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                d[i][j]=1+d[i-1][j-1];
            }
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }

    while(i && j){
        if(a[i]==b[j]){
            c[p++] = a[i];
            i--; j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    fout<<d[n][m]<<"\n";

    for(i=p-1; i-1; i--)
        fout<<c[i]<<" ";
}

int main()
{
    citire();
    dp();
}
