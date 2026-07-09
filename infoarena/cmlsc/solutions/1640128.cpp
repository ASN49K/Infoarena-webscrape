#include<fstream>
using namespace std;
ifstream fin("scm.in");
ofstream fout("scm.out");
int lcs[1030][1030];
int n, m;
int x[1030],y[1030],v[1030];
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<=m;i++)
        fin>>y[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(x[i]==y[j])lcs[i][j]=1+lcs[i-1][j-1];
        else if(lcs[i][j-1]>=lcs[i-1][j])
            lcs[i][j]=lcs[i][j-1];
        else lcs[i][j]=lcs[i-1][j];
    fout<<lcs[n][m]<<'\n';
    int l=n,c=m,lung=0;
    while(lcs[l][c]!=0){
        if(x[l]==y[c]){lung++;v[lung]=x[l];l--;c--;}
        else if(lcs[l][c]==lcs[l-1][c])l--;
        else c--;
    }
    for(int i=lung;i>0;i--)
        fout<<v[i]<<" ";
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}
