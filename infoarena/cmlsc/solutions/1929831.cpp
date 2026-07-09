#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, nr;
int a[1025], b[1025];
int lcs[10250][10250];
int v[1025];

int main()
{
    int i,j;
    fin>>m>>n;
    for(i=1;i<=m;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    fout<<lcs[m][n]<<endl;
    i=m;
    j=n;
    while(i>0 && j>0)
    {
        if(lcs[i][j]==lcs[i-1][j-1]+1)
        {
            v[++nr]=a[i];
            i--;
            j--;
        }
        else
        {
            while(i>0 && j>0)
            {
                while(lcs[i-1][j-1]==lcs[i][j])
                    i--;
                while(lcs[i][j-1]==lcs[i][j])
                    j--;
                i--;
                j--;
                v[++nr]=a[i+1];
            }
        }
    }
    for(i=nr;i>=1;i--)
    {
        fout<<v[i]<< " ";
    }
}
