#include <fstream>
#include <vector>
#define MX 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,a[MX],b[MX];
int l[MX][MX];
vector<int> d;

void citire()
{
    int i;
    fin>>m>>n;
    for(i=1; i<=m; i++) fin>>a[i];
    for(i=1; i<=n; i++) fin>>b[i];
}

int main()
{
    int i,j;
    citire();

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i] == b[j])
            {
                l[i][j] = l[i-1][j-1] + 1;
            }
            else
            {
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }

    fout<<l[m][n]<<'\n';

    i = m; j = n;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            d.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if(l[i-1][j] > l[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    while(!d.empty())
    {
        fout<<d.back()<<' ';
        d.pop_back();
    }

    fin.close(); fout.close();
    return 0;
}
