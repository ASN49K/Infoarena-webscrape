# include <fstream>
# define DIM 1034
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[DIM][DIM],a[DIM],b[DIM],sol[DIM],n,m,i,j,k;
int main () {
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    }
    fout<<v[n][m]<<"\n";
    while(n&&m){
        if(a[n]==b[m]){
            sol[++k]=a[n];
            n--;
            m--;
        }
        else{
            if(v[n-1][m]>v[n][m-1])
                n--;
            else
                m--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
    return 0;
}
