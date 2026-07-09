#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,v[1050][1050],a[1050],b[1050],sol[1050],s;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
    for(int i=n,j=m;i;){
        if(a[i]==b[j])sol[++s]=a[i],i--,j--;
        else if(v[i-1][j]<v[i][j-1])j--;
        else i--;
    }
    fout<<v[n][m]<<"\n";
    for(int i=s;i;i--)fout<<sol[i]<<" ";
    return 0;
}
