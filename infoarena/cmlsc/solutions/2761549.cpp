#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

long long euclid(long long a,long long b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}

void EUCLID()
{
    long T;
    fin>>T;
    long long a,b;
    while(T--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    fin.close();
    fout.close();
}

int main()
{
    int m,n;
    fin>>m>>n;
    vector<int>a,b;
    vector<vector<int>>c(m+1, vector<int>(n+1,0));
    int i,j;
    a.push_back(0);
    for(i=1;i<=m;i++)
    {
        fin>>a[i];
    }
    b.push_back(0);
    for(i=1;i<=n;i++)
    {
        fin>>b[i];
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i] == b[j])
            {
                c[i][j] = c[i-1][j-1]+1;
            }
            else c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    }
    vector<int>res;
    fout<<c[m][n]<<'\n';

    int contor = c[m][n];
    for(i=m,j=n;i;)
    {
        if(a[i] ==b[j])
        {
            res.push_back(a[i]);
            i--;
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
            j--;
        else i--;
    }
    for(i=res.size()-1;i>=0;i--)
    {
        fout<<res[i]<<" ";
    }
    return 0;
}