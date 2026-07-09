#include <iostream>
#include <fstream>
#define nmax 1024
using namespace std;
 
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
  
  int m,n,a[nmax],b[nmax],sol[nmax],lgsol,d[nmax][nmax];
 
void read()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
        fin>>a[i];
    for(int i=1; i<=n; i++)
        fin>>b[i];
    fin.close();
}
 
void solve()
{
    int i ,j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i] == b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
 
    i=m; j=n;
    while(i)
    {
        if(a[i] == b[j])
            {
                sol[++lgsol]=a[i];
                i--;
                j--;
            }
        else
        if(d[i-1][j] < d[i][j-1])
            j--;
        else i--;
    }
 
    fout<<lgsol<<"\n";
    for(i=lgsol; i>=1; i--)
        fout<<sol[i]<<" ";
}
int main()
{
    read();
    solve();
    return 0;
}
