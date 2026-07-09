#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int dim=1029;

int rez[dim],k,m,n,a[dim],b[dim],L[dim][dim];
int lcs(int a[],int b[],int m,int n){
    int i,j;
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j){
            if(a[i]==b[j])
                L[i][j]=L[i-1][j-1]+1,rez[++k]=a[i];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
        return L[m][n];
}

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int main(){
   fin>>m>>n;
   for(int i=1;i<=m;++i)
    fin>>a[i];
   for(int i=1;i<=n;++i)
    fin>>b[i];
    fin.close();
    fout<<lcs(a,b,m,n)<<'\n';
    for(int i=1;i<=k;++i)
        fout<<rez[i]<<" ";
    fout.close();
return 0;
}

