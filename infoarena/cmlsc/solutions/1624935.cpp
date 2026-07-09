#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
short m,n;
short table[1025][1025];
unsigned char v1[1025],v2[1025];
queue<unsigned char> sir;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);

    for(int i=0; i<m; i++)
        scanf("%d",&v1[i]);

    for(int i=0; i<n; i++)
        scanf("%d",&v2[i]);

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(v1[i-1]==v2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
                sir.push(i-1);
            }
            else table[i][j]=max(table[i-1][j],table[i][j-1]);
        }

    printf("%d\n",table[m][n]);
    while(!sir.empty())
    {
        printf("%d ",v1[sir.front()]);
        sir.pop();
    }

}
