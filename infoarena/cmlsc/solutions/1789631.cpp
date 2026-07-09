#include <iostream>
#include <fstream>
using namespace std;
int n,m,s[1025],t[1025],k[1025][1025],i,j,ma,l;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(i=1;i<=n;i++)f>>s[i];
    for(i=1;i<=m;i++)f>>t[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(s[i]!=t[j])k[i][j]=max(k[i][j-1],k[i-1][j]);
            else k[i][j]=k[i-1][j-1]+1;
    }
    ma=k[n][m];i=n;j=m;
    g<<ma<<endl;
    for(l=1;l<=ma;l++)
    {
        while(k[i][j-1]==k[i][j])j--;
        while(k[i-1][j]==k[i][j])i--;
        g<<s[i]<<" ";
        i--;
        j--;
    }
}
