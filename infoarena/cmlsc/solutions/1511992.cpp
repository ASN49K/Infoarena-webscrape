#include <bits/stdc++.h>
#define Nmax 1027

using namespace std;

int a[Nmax],b[Nmax],dp[Nmax][Nmax],sir[Nmax];

inline void Read()
{
    int i;
    ifstream fin("cmlsc.in");
    fin>>a[0]>>b[0];
    for(i=1;i<=a[0];i++)
        fin>>a[i];
    for(i=1;i<=b[0];i++)
        fin>>b[i];
    fin.close();
}

inline void CMLSC()
{
    int i,j;
    for(i=1;i<=a[0];i++)
        for(j=1;j<=b[0];j++)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

}

inline void Solve()
{
    int i,j,k;
    CMLSC();
    i=a[0];j=b[0];k=1;sir[0]=dp[a[0]][b[0]];
    while(i>0&&j>0)
        if(a[i]==b[j])
        {
            sir[k]=b[j];
            i--;j--;
            k++;
        }
        else if(dp[i-1][j]>dp[j-1][i])
                i--;
            else
                j--;
    sir[0]=k;
}

inline void Write()
{
    int i;
    ofstream fout("cmlsc.out");
    fout<<sir[0]<<"\n";
    for(i=sir[0];i>0;i--)
        fout<<sir[i]<<" ";
    fout<<"\n";
    fout.close();
}

int main()
{
    Read();
    Solve();
    Write();
    return 0;
}
