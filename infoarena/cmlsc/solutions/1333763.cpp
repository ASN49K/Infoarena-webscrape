#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int S[1025][1025],V[1025],W[1025],n,m;
int main()
{
    in>>n>>m;
    for (int i=1;i<=n;i++)
        in>>V[i];
    for(int i=1;i<=m;i++)
        in>>W[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(V[i]==W[j])
            S[i][j]=S[i-1][j-1]+1;
        else
            S[i][j]=max(S[i-1][j],S[i][j-1]);
    }
        out<<S[n][m]<<endl;
        int st=S[n][m],t[1025];

        int i=n,j=m;
        while(st)
        {
            if(V[i]==W[j])
                {
                    t[st--]=V[i];
                    i-=1;
                    j-=1;
                }
            else if(S[i-1][j]>S[i][j-1])
                i=i-1;
            else
                j=j-1;
        }

        for (int i=S[n][m];i>=1;i--)
            out<<t[i]<<' ';
            in.close();
            out.close();
    return 0;
}
