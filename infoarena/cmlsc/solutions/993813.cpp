#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define baza 1
#define MAX 1025
#define MOD 9973
typedef long long int lli;



int a[MAX], b[MAX], s[MAX][MAX], i, j, n, m;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }

    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                s[i][j]=1+s[i-1][j-1];
            }
            else
            {
                s[i][j]=max(s[i][j-1], s[i-1][j]);
            }
        }
    }
    int k=0;
    fout<<s[n][m]<<"\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           if(s[i][j]==k+1)
           {
               fout<<a[i]<<" ";
               k++;
           }

        }
    }




    return 0;
}
