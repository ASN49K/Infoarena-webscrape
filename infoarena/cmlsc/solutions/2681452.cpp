#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,x[1025],y[1025],n,m,a[1025],k,nr;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(j=1;j<=m;j++)
        fin>>y[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j]) {
                nr++;
                k++;
                a[k]=x[i];
            }
    fout<<nr<<'\n';
    for(k=1;k<=nr;k++)
        fout<<a[k]<<" ";
    return 0;
}
