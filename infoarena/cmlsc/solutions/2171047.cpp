# include <fstream>
# define DIM 1034
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int d[DIM][DIM],t[DIM][DIM],a[DIM],b[DIM],sol[DIM],n,m,i,j,nr;
int main () {
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
                t[i][j]=2;
            }
            else{
                if(d[i-1][j]>d[i][j-1]){
                    d[i][j]=d[i-1][j];
                    t[i][j]=1;
                }
                else
                    d[i][j]=d[i][j-1];
            }
    fout<<d[n][m]<<"\n";
    while(n>0&&m>0){
        if(a[n]==b[m])
            sol[++nr]=a[n];
        if(t[n][m]==2){
            n--;
            m--;
        }
        else{
            if(t[n][m]==1)
                n--;
            else
                m--;
        }
    }
    for(i=nr;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
    return 0;
}
