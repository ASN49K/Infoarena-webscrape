#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i,j,n,m;

int a[1025],b[1025],v[1025];

int qw[1025][1025];

int maxx(int a,int b)
{
    if(a>b) return a;
    return b;
}

int  cmlsc()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                qw[i][j]=1+qw[i-1][j-1];
            else
                qw[i][j]=maxx(qw[i-1][j],qw[i][j-1]);
        }


    int i=n,j=m,s=0;

    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
            v[++s]=a[i],i--,j--;

        else

            if(qw[i-1][j]>qw[i][j-1])
                i--;

            else
                j--;
    }

    fout<<qw[n][m]<<'\n';


    for(int i=s;i>=1;i--)
        fout<<v[i]<<' ';

    return 0;
}

int main()
{
    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>a[i];

    for(i=1;i<=m;i++)
        fin>>b[i];


    cmlsc();

    return 0;
}
