#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1024],b[1024],pd[1024][1024];
void cit(){
    fin>>m>>n;
    int i;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}
void afissir(int i,int j){
    if(pd[i][j]!=0)
        if(a[j]==b[i]){
            afissir(i-1,j-1);
            fout<<a[j]<<" ";}
    else
        if(pd[i-1][j]>=pd[i][j-1])
            afissir(i-1,j);
        else
            afissir(i,j-1);
}

int main(){
    cit();
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(b[i]==a[j])
                pd[i][j]=pd[i-1][j-1]+1;
            else
                pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
    fout<<pd[n][m]<<'\n';
    afissir(n,m);
    return 0;}
