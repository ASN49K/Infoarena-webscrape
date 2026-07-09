#include <iostream>
#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int n,m,a[1025],b[1025],c[1025][1025],s[1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    int k=0;
    for(int i=n,j=m;i;)
        if(a[i]==b[j])
            s[++k]=a[i],i--,j--;
        else if(c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    fout<<k<<endl;
    for(int i=k;i;--i)
        fout<<s[i];
    return 0;
}
