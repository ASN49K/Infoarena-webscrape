#include <bits/stdc++.h>

using namespace std;

int m, n, v1[1111], v2[1111], din[1111][1111], sir[1111], ans;

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        fin>>v1[i];
    }
    for (int i=1; i<=m; ++i)
    {
        fin>>v2[i];
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            if (v1[i]==v2[j])
            {
                din[i][j]=1+din[i-1][j-1];
            }
            else
            {
                din[i][j]=max(din[i-1][j], din[i][j-1]);
            }
        }
    }

    for (int i=m,j=n; i;)
    {
        if (v1[i]==v2[j])
        {
            sir[++ans]=v1[i];
            --i;
            --j;
        }
        else
        {
            if (din[i-1][j] < din[i][j-1])
            {
                --j;
            }
            else
            {
                --i;
            }
        }
    }
    fout<<ans;
    for (int i=ans; i>=1; --i)
    {
        fout<<sir[i]<<" ";
    }
    return 0;
}

