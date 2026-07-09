#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1025],b[1025],lung[1024][1024],sir[1024];
int main()
{
    fin>>n>>m;
    for(i=0;i<n;++i)fin>>a[i];
    for(i=0;i<m;++i)fin>>b[i];
    if(a[0]==b[0])lung[0][0]=1;
    for(i=1;i<n;++i)if(a[i]==b[0])lung[i][0]=1;else lung[i][0]=lung[i-1][0];
    for(i=1;i<m;++i)if(a[0]==b[i])lung[0][i]=1;else lung[0][i]=lung[0][i-1];
 for(i=1;i<n;++i)
    for(j=1;j<m;++j)
    {

        if(a[i]==b[j])lung[i][j]=lung[i-1][j-1]+1;
        else
            lung[i][j]=max(lung[i-1][j],lung[i][j-1]);

    }
   fout<<lung[n-1][m-1]<<" ";
    i=n-1;
    j=m-1;
    int k=0;
    while(i>=0&&j>=0)
    {
        if(a[i]==b[j]){sir[++k]=a[i];--i;--j;}
        else if(i-1>=0&&lung[i][j]==lung[i-1][j])--i;
        else j--;
    }
    for(i=k;i>=1;--i)fout<<a[i]<<" ";
    return 0;
}
