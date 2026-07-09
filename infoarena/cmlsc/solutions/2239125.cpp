#include <bits/stdc++.h>
using namespace std;
stack <int> q;
const int nmax=1030;
int A[nmax],B[nmax],n,m;
int l[nmax][nmax];
int main()
{int i,j;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n>>m;
    for (i=1;i<=n;i++)
    in>>A[i];
    for (i=1;i<=m;i++)
    in>>B[i];
    l[0][0]=l[0][1]=l[1][0]=0;
    for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (A[i]==B[j])
                    l[i][j]=l[i-1][j-1]+1;
                else
                    l[i][j]=max(l[i][j-1],l[i-1][j]);
            }
        }
    out<<l[n][m]<<"\n";
    i=n;j=m;
    while (l[i][j]!=0)
    {
        if (A[i]!=B[j])
        {
            if (l[i][j-1]<l[i-1][j])
                i--;
            else
                j--;
        }
        else
        {
            q.push(A[i]);
            i--;
            j--;
        }
    }
    while (!q.empty())
    {
        out<<q.top()<<" ";
        q.pop();
    }
    out<<"\n";
}
