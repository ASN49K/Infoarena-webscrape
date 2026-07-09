#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int LMAX=1050;

int m,n;
int v[LMAX],x[LMAX],D[LMAX][LMAX],s[LMAX];

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int i=1; i<=m; i++)
        fin>>x[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i]==x[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i][j-1],D[i-1][j]);
        }
    }
    int i=n,j=m,contor=0;
    while(i>=1 && j>=1)
    {
        if (v[i] == x[j])
            s[++contor] = v[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    }
    fout<<contor<<endl;
    for(i=contor; i>=1; --i)
        fout<<s[i]<<" ";



    return 0;
}
