#include <iostream>
#define maxim(a,b) a>b? a:b
#include <fstream>
#include <stack>
using namespace std;

int main()
{
    unsigned short m, n;
    stack<short> q;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
        f>>n>>m;
        unsigned short s1[n+1], s2[m+1], t[n+1][m+1];

        for (unsigned int i=0; i<n; i++)
                f>>s1[i+1];

        for (unsigned int i=0; i<m; i++)
                f>>s2[i+1];

    for (unsigned int i=0; i<=n; i++)
        for (unsigned int j=0; j<=m; j++)
            t[i][j]=0;


    for (unsigned int i=1; i<=n; i++)
    {
        for (unsigned int j=1; j<=m; j++)
        {
            if (s1[i]==s2[j])
                t[i][j]=t[i-1][j-1]+1; else
            t[i][j]=maxim(t[i-1][j], t[i][j-1]);
        }
    }
    g<<t[n][m]<<"\n";
    while (n>0&&m>0)
    {
        if (s1[n]==s2[m])
        {
            q.push(s1[n]);
            n--; m--;
        }
        else
        {
           if (maxim(t[n][m-1],t[n-1][m])==t[n][m-1])
                m--; else
                n--;
        }
    }
    while (!q.empty())
    {
        g<<q.top()<<" ";
        q.pop();
    }
    return 0;
}
