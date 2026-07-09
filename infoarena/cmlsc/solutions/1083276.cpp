#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short a[1025],b[1025],l[1025][1025];
int main()
{
    short n,m,i,j,max,x;
    fin>>n>>m;
    for(i=0;i<=n-1;i++)
        fin>>a[i];
    for(i=0;i<=m-1;i++)
        fin>>b[i];
    l[0][0]=(a[0]==b[0])?1:0;
    for(i=1;i<=n-1;i++)
        l[i][0]=(a[i]==b[0])?1:l[i-1][0];
    for(j=1;j<=m-1;j++)
        l[0][j]=(a[0]==b[j])?1:l[0][j-1];
    for(i=1;i<=n-1;i++)
        for(j=1;j<=m-1;j++)
        {
            max=0;
            x=(a[i]==b[j])? l[i-1][j-1]+1:0;
            if(x>=l[i-1][j]&&x>=l[i][j-1])max=x;
            else
            {
                if(l[i-1][j]>x&&l[i-1][j]>l[i][j-1])max=l[i-1][j];
                else max=l[i][j-1];
            }
            l[i][j]=max;
        }
    fout<<l[n-1][m-1]<<'\n';
    i=n-1;
    j=m-1;
    while(i>=0&&j>=0)
    {
        if(a[i]==b[j])
        {
            fout<<a[i]<<" ";
            i--;
            j--;
        }
        else
        {
            if(i-1>=0&&l[i][j]==l[i-1][j])i--;
            else j--;
        }
    }
    return 0;
}
