#include <iostream>
#include <fstream>
using namespace std;

int v[1025][1025],n,m,a[1025],b[1025],sol[1025];

void Solve()
{
int n,m,i,j;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
fin>>n>>m;
for(int i=1;i<=n;i++)
    fin>>a[i];
for(int j=1;j<=m;j++)
    fin>>b[j];
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(a[i]==b[j])
     v[i][j] = 1 + v[i - 1][j - 1];
            else v[i][j] = max(v[i - 1][j],v[i][j - 1]);
    fout << v[n][m] <<endl;
    int k = 0;
    i = n;
    j = m;
    while (i)
    {
        if (a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else if (v[i - 1][j] < v[i][j - 1])
            j--;
        else i--;
    }
    for (i = k; i >= 1; i--)
        fout << sol[i] <<" "<<endl;
    fout.close();

}
int main()
{
    Solve();
    return 0;
}

