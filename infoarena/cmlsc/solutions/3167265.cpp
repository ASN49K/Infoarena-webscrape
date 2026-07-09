#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int d[1025][1025];
int x[1025],y[1025],n,m;
void lcs(){
    int i,j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
}
void afisare(){
    int i,j,t[1025],k;
    fout<<d[n][m]<<'\n';
    k=0;
    i=n,j=m;
    while(i>0 && j>0){
        if(x[i]==y[j]){
            t[++k]=x[i];
            i--;
            j--;
        }
        else if(d[i][j-1]>d[i-1][j]) j--;
        else i--;
    }
        for(int i=k;i>=1;i--)
            fout<<t[i]<<" ";

}
int main() {
    fin>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>x[i];
    for(int i=1;i<=m;++i)
        fin>>y[i];
    lcs();
    afisare();
    return 0;
}
