#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,n,k,m,a[1025],b[1025],v[1025][1025],tata[1025][1025],nr,sol[1025];
void recursiv(int i, int j){
    if(tata[i][j]!=0){
        if(tata[i][j]==1)
            recursiv(i-1,j);
        else if(tata[i][j]==2){
            sol[k]=a[i];
            k--;
            recursiv(i-1,j-1);
        }
        else
            recursiv(i,j-1);
    }
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i]==b[j]){
                v[i][j]=v[i-1][j-1]+1;
                tata[i][j]=2;
            }
            else{
                if(v[i-1][j]>v[i][j-1]){
                    v[i][j]=v[i-1][j];
                    tata[i][j]=1;
                }
                else{
                    v[i][j]=v[i][j-1];
                    tata[i][j]=3;
                }
            }
    }
    nr=v[n][m];
    fout<<nr<<'\n';
    i=n;
    j=m; k=nr;
    recursiv(n,m);
    for(i=1;i<=nr;i++)
        fout<<sol[i]<<' ';
    return 0;
}
