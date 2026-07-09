#include <bits/stdc++.h>
#define DimMax 1030
#define ValMax 260

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int x;
int a[DimMax];
int sol[DimMax];
bool E[ValMax];
int main()
{
    fin>>n>>m;
    for(int i = 1;i <= n;i++)
        fin>>a[i];
    for(int i = 1;i <= m;i++)
    {
        fin>>x;
        E[x] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        if(E[a[i]] == 1)
        {
            sol[0]++;
            sol[sol[0]] = a[i];
        }
    }
    fout<<sol[0]<<'\n';
    for(int i = 1;i <= sol[0];i++)
        fout<<sol[i]<<" ";
    return 0;
}
