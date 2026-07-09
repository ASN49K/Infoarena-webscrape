#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], com[1025][1025], sol[1025];

int main()
{
    int n, m;
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                com[i][j]=1+com[i-1][j-1];
            }
            else
            {
                com[i][j]=max(com[i-1][j], com[i][j-1]);
            }
        }
    }
    fout<<com[n][m]<<"\n";
    int i=n, j=m, k=com[n][m];
    while(k>0)
    {
        if(a[i]==b[j])
        {
            sol[k--]=a[i];
            i--;
            j--;
        }
        else if(com[i-1][j]>com[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i=1; i<=com[n][m]; i++)
    {
        fout<<sol[i]<<" ";
    }
    return 0;
}
