#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream input("cmlsc.in");
ofstream output("cmlsc.out");
vector <int> sol;
int d[1040][1040],poz,n,m,a[1040],b[1040];
int main()
{
    int i,j;
    input >> n >> m;
    for(i=1; i<=n; i++)
    {
        input >> b[i];
    }
    for(i=1; i<=m; i++)
    {
        input >> a[i];
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    poz=d[m][n];
    output << poz << '\n';
    while(poz)
    {
        if(d[m-1][n-1]+1==d[m][n] && a[m]==b[n])
        {
            n--;
            m--;
            poz--;
            sol.push_back(a[m+1]);
        }
        else if(d[m-1][n]==poz)
        {
            m--;
        }
        else if(d[m][n-1]==poz)
        {
            n--;
        }
    }
    for(i=sol.size()-1; i>=0; i--)
    {
        output << sol[i] << " ";
    }
}
