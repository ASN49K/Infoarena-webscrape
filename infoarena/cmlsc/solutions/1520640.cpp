#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1026
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[NMAX],b[NMAX],d[NMAX][NMAX];
vector<int> sol;
int main()
{
    in >> n >> m;

    for(int i=1;i<=n;i++)
        in >> a[i];
    for(int j=1;j<=m;j++)
        in >> b[j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]= d[i-1][j-1]+1;
            else
                d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    out << d[n][m] << "\n";



    for(int i=n,j=m;i;)
    {
        if(a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--;j--;
        }
        else if(d[i-1][j] < d[i][j-1])
        {
            j--;
        }
        else
            i--;
    }
    for(int i=sol.size()-1;i>=0;i--)
    {
        out << sol[i] << " " ;
    }
    return 0;
}
