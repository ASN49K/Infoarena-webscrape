#include <iostream>
#include<fstream>
using namespace std;
#define maxim(a,b) ((a>b) ? a : b)
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1005],b[1005],d[1005][1005],sir[1005],br;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[i])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=n; int j=m; i)
    {
        if(a[i]==b[j])
        {
            br++;
            sir[br]=a[i],--i,--j;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                --j;
            else
                --i;
        }
    }
   fout<<br<<endl;
    for(int i=br; i>=1; i--)
        fout<<sir[i]<<" ";



    return 0;
}
