#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int maxim(int q,int w)
{
    if(q>w)
        return q;
    else return w;
}
int n,lcs[200][200],i,j,m,nb,k,sir[200],a[200],b[200];
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=maxim(lcs[i-1][j],lcs[i][j-1]);
        }
    i=m;
    j=n;
    while(i>0||j>0)
    {
        if(a[i]==b[j])
        {
            k++;
            sir[k]=a[i];
            i--;
            j--;
        }
        else
            if(lcs[i-1][j]<lcs[i][j-1])
                j--;
            else i--;
    }
    fout<<k<<'\n';
    for(i=k;i>=1;i--)
        fout<<sir[i]<<' ';
    fout.close();
    return 0;
}
