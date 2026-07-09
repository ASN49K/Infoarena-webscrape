#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1030],b[1030],d[1030][1030],c[1030],k;
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int j=1;j<=m;j++)
        fin >> b[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    }
    int i=n,j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;
        }
        else if(d[i][j-1]>d[i-1][j])
            j--;
        else i--;
    }
    fout << k << "\n";
    for(int t=k;t>=1;t--)
        fout << c[t] << " ";
    return 0;
}
