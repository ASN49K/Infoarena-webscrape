#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,v1[1025],v2[1025],d[1025][1025],s[1025],k;

int main()
{

    fin>>m;
    fin>>n;

    for(int i=1;i<=m;i++)
        fin>>v1[i];
    for(int j=1;j<=n;j++)
        fin>>v2[j];

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v1[i]==v2[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
            }

            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

        }
    }
    fout<<d[m][n]<<endl;

    for(int i=m,j=n;i;)
    {
        if(v1[i]==v2[j])
            s[++k]=v1[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    for(int i=k;i>0;--i)
        fout<<s[i]<<" ";

}
