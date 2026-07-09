#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void subsir(int a[500][500],int v1[500], int v2[500],int x,int y)
{
    int v[500];
    int t=0;
    int i,j;
    for(i=0;i<=x;++i)
        for(j=0;j<=y;++j)
    {
        if(i==0||j==0)
            a[i][j]=0;
        else if(v1[i]==v2[j])
            a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    fout<<a[x][y]<<endl;
   int s=1;
   int j1=y;
   int i1=x;
    while(s)
    {
        if(a[i1-1][j1]==a[i1][j1])
        {
            i1=i1-1;
            j1=j1;
        }
        else if(a[i1][j1-1]==a[i1][j1])
            {
                i1=i1;
            j1=j1-1;
           }
       else
           {
            j1=j1-1;
            i1=i1-1;
            v[t]=v2[j1+1];
            t++;
           }
           if(a[i1][j1]==0)
            s=0;

    }
    for(i=t-1;i>=0;--i)
        fout<<v[i]<<' ';

}
int main()
{
    int x,v1[500],v2[500],y,a[500][500];
    fin>>x>>y;
    int i,j;
    for(i=1;i<=x;++i)
        fin>>v1[i];
    for(i=1;i<=y;++i)
        fin>>v2[i];
        subsir(a,v1,v2,x,y);
    return 0;
}
