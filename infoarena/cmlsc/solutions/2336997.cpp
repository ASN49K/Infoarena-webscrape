#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector <short> a,b;
short c[1025][1025];
int n,m;
void citire()
{
    short nr;
    a.push_back(0);
    b.push_back(0);
    fin>>n>>m;
    for(int i=0;i<n;++i)
    {
        fin>>nr;
        a.push_back(nr);
    }
    for(int i=0;i<m;++i)
    {
        fin>>nr;
        b.push_back(nr);
    }
}
void computeC()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else
                c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    }
}
vector<short> getLCS(int i, int j)
{
    vector<short> lcs;
    if(i==0 || j==0)
    {
        return lcs;
    }
    if(a[i]==b[j])
    {
        lcs=getLCS(i-1,j-1);
        lcs.push_back(a[i]);
        return lcs;
    }
    if(c[i-1][j]>c[i][j-1])
    {
        lcs=getLCS(i-1,j);
        return lcs;
    }
    lcs=getLCS(i,j-1);
    return lcs;
}
int main()
{
    citire();
    computeC();
    fout<<c[n][m]<<"\n";
    vector<short> sol = getLCS(n,m);
    for(int i=0;i<sol.size();++i)
    {
        fout<<sol[i]<<" ";
    }
    return 0;
}
