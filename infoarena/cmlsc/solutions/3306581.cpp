#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1030],b[1030],d[1030][1030],k,sir[1030];

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    int i=n,j=m;
    while(i>=1)
        if(a[i]==b[j])
        {
            sir[++k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    fout<<k<<endl;
    for(i=k;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
