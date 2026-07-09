#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1030],b[1030],c[1030],k;
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    int pf=1;
    for(int j=1;j<=m;j++)
    {
        int x;
        fin >> x;
        bool ok=0;
        for(int i=pf;i<=n;i++)
        {
            if(a[i]==x)
            {
                ok=1;
                pf=i;
                break;
            }
        }
        if(ok) c[++k]=x;
    }
    fout << k << "\n";
    for(int t=1;t<=k;t++) fout << c[t] << " ";
    return 0;
}
