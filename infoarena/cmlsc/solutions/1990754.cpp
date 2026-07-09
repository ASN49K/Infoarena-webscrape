#include <iostream>
#include <fstream>
using namespace std;
int n,m,i,o,d[1025][1025],a[1025],b[1025],l,x[1025],k;
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(o=1;o<=m;o++)
        {
            if(a[i]==b[o])d[i][o]=d[i-1][o-1]+1;
            else d[i][o]=max(d[i-1][o],d[i][o-1]);
        }
    }
    i=n;o=m;l=d[n][m];
    while(l)
    {
        k=0;
        //fout<<i<<" "<<o;
        if(a[i]==b[o])
        {
            //fout<<"###";
            x[l]=a[i];
            l--;
            i--;
            k=1;
        }
        //fout<<"\n";
        if(o-1)o--;
        else if(!k)i--;
    }
    fout<<d[n][m]<<"\n";
    for(i=1;i<=d[n][m];i++)fout<<x[i]<<" ";
    return 0;
}
