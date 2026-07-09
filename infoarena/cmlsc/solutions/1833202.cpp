#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n,m,a[1030],b[1030],x[1030][1030],st[1030],vf;

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
}

int maxim(int a ,int b)
{
    if(a>b)
        return a;
    return b;
}

void rezolv()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i] == b[j])
            x[i][j] = x[i-1][j-1]+1;
        else
            x[i][j] = maxim(x[i-1][j],x[i][j-1]);
    }
}

void afisare()

{
    int i=n,j=m;
    while(i!=0&&j!=0)
    {
        if(x[i][j]==x[i-1][j-1]+1)
            st[++vf]=a[i],i--,j--;
        else
        if(x[i][j]==x[i-1][j])
            i--;
        else
            j--;
    }
    fout<<vf<<"\n";
    for(int i=vf;i>=1;i--)
        fout<<st[i]<<" ";
}

int main()
{
    citire();
    rezolv();
    afisare();
    return 0;
}
