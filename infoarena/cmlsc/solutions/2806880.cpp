#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025][1025],x[1025],y[1025],solve[1025],n,m;
void dinamica()
{int i,j;

    a[0][0]=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
       if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
         else a[i][j]=max(a[i-1][j],a[i][j-1]);

}

void afisare()
{
    int k,l;

    l=a[n][m];
    fout<<l<<'\n';
    int i=n,j=m;
    while(l)
    {
        if(x[i]==y[j])
        {
            solve[l]=x[i];
            cout<<x[i]<<" ";l--;i--;j--;
        }
        else if(a[i-1][j]<a[i][j-1]) j--;
        else i--;
    }
    for(k=1;k<=a[n][m];k++)
        fout<<solve[k]<<" ";
}
int main()
{ int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>x[i];
    for(j=1;j<=m;j++) fin>>y[j];
    dinamica();
    afisare();
    return 0;
}
