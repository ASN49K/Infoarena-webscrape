#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1050],b[1050],D[1050][1050],sol[1050],k,nr;
int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
               D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    fout<<D[n][m]<<"\n";
    nr=D[n][m], i=n, j=m;
    while(nr){
        if(a[i]==b[j]){
            sol[++k]=a[i];
            i--, j--, nr--;
        }else{
            if(D[i-1][j]>D[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
