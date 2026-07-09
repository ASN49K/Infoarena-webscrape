#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int LCS[1025][1025],i,j,A[1025],B[1025],n,m,sub,dr[1025];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>A[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>B[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(B[j]==A[i])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    i=n;
    j=m;
    while(i)
    {
        if(A[i]==B[j])
        {
            dr[++sub]=A[i];
            i--;
            j--;
        }else{
            if(LCS[i-1][j]<LCS[i][j-1])j--;
            else i--;
        }
    }
    fout<<sub<<'\n';
    for(i=sub;i>=1;i--)
    {
        fout<<dr[i]<<" ";
    }
    return 0;
}
