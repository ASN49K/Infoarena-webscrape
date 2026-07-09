#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1030],b[1030],c[1030];
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int j=1;j<=m;j++)
        fin >> b[j];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int i=1,j=1,k=0;
    while(i<=n && j<=m)
    {
        if(a[i]>b[j]) j++;
        else if(a[i]<b[j]) i++;
        else
        {
            c[++k]=a[i];
            i++;
            j++;
        }
    }
    fout << k << "\n";
    for(int t=1;t<=k;t++) fout << c[t] << " ";
    return 0;
}
