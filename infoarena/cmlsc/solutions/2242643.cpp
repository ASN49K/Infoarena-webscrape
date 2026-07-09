#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[1040],b[1040];
int v[1030][1030];
vector <int> rasp;

void backtrack(int i,int j)
{
    if(i==0&&j==0)
        return;
    if(a[i]==b[j])
    {
        rasp.push_back(a[i]);
        backtrack(i-1,j-1);
        return;
    }
    if(v[i][j-1]>v[i-1][j])
        backtrack(i,j-1);
    else
        backtrack(i-1,j);
}


int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }

    fout<<v[n][m]<<"\n";
    backtrack(n,m);
    for(int i=rasp.size()-1;i>=0;i--)
        fout<<rasp[i]<<" ";
    return 0;
}
