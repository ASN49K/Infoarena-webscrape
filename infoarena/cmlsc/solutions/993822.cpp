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



int a[MAX], b[MAX], s[MAX][MAX], i, j, n, m,ki[MAX];

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
    int k=s[n][m];
    fout<<s[n][m]<<"\n";
    i=n;
    j=m;
    int l=0;
    while(k)
    {
        while(s[i-1][j]==k)
        {
            i--;
        }
        while(s[i][j-1]==k)
        {
            j--;
        }
        ki[++l]=a[i];
        k--;
        i--;
        j--;
    }
    for(i=l;i>=1;i--)
    {
        fout<<ki[i]<<" ";
    }






    return 0;
}
