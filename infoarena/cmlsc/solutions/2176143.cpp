#include <fstream>
#include <vector>
#define LMAX 1025

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[LMAX];
int b[LMAX];

int pd[LMAX][LMAX];
int n, m;

int MAX(int a, int b, int c);
vector<int> sol;

int main()
{
    fin>>n>>m;
    for (int i=1;i<=n;i++)
        fin>>a[i];
    for (int i=1;i<=m;i++)
        fin>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
             if (a[i]==b[j])
                 pd[i][j]=pd[i-1][j-1]+1;
                 else
                 pd[i][j]=MAX(pd[i-1][j-1],pd[i-1][j],pd[i][j-1]);
    fout<<pd[n][m]<<'\n';
    for (int i=n, j=m;i>=1&&j>=1;)
        if (a[i]==b[j])
            {
             sol.push_back(a[i]);
             i--;
             j--;
            }
            else if (pd[i-1][j]>pd[i][j-1])
                i--; else j--;
    for (int i=sol.size()-1;i>=0;i--)
        fout<<sol[i]<<' ';
    fin.close();
    fout.close();
}

int MAX(int a, int b, int c)
{
    int m=a;
    if (b>m)
        m=b;
    if (c>m)
        m=c;
    return m;
}
