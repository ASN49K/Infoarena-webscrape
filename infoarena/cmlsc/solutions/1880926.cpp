#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1024],b[1024],pd[1024][1024],sol[1024];
void cit(){
    fin>>m>>n;
    int i;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}
void gensubsir(int i,int j,int n){
    if(n==0)
        return ;
    if(pd[i-1][j-1]+1==pd[i][j]){
        sol[n]=b[i];
        gensubsir(i-1,j-1,n-1);}
    else
        if(pd[i-1][j]>=pd[i][j-1])
            gensubsir(i-1,j,n);
        else
            gensubsir(i,j-1,n);
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
    gensubsir(n,m,pd[n][m]);
    for(i=1;i<=pd[n][m];i++)
        fout<<sol[i]<<" ";
    return 0;}
