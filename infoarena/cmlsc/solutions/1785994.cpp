#include <iostream>
#include <fstream>

using namespace std;

int a[1025],b[1025],dp[1025][1025],m,n,MAX=0;

void citire()
{
    ifstream fin("cmlsc.in");
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
}

void prelucrare()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(dp[i][j]>MAX)
                MAX=dp[i][j];
        }
}

void afisare()
{
    ofstream fout("cmlsc.out");
    fout<<MAX<<"\n";

    int sir[1025],p=0;

    int i=m,j=n;
    while(dp[i][j])
    {
        if(a[i]==b[j])
        {
            sir[p++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int x=p-1;x>=0;x--)
        fout<<sir[x]<<" ";
}

int main()
{
    citire();
    prelucrare();
    afisare();
    return 0;
}
