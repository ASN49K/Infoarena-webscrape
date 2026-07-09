#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,k,sol[1025],a[1025],b[1025],d[1025][1025];

int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    i=n; j=m;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            sol[++k]=a[i];
            i--;
            j--;
        }else{
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }

    fout<<d[n][m]<<"\n";
    for(;k;k--)
        fout<<sol[k]<<" ";

    return 0;
}
