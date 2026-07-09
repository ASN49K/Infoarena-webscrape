#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
int m,n;
int table[1025][1025];
int action[1025][1025];
int v1[1025],v2[1025];
stack<int> sir;

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
                //0=nothing;1=left;2=up;3=diag;
                action[i][j]=3;
            }
            else
            {
                if(table[i-1][j]>table[i][j-1])
                {
                    table[i][j]=table[i-1][j];
                    action[i][j]=2;
                }
                else
                {
                    table[i][j]=table[i][j-1];
                    action[i][j]=1;
                }
            }
        }

    printf("%d\n",table[m][n]);


    int x=m,y=n;

    while(table[x][y])
    {
        switch(action[x][y])
        {
        case 3:
            sir.push(v2[y-1]);
            x--;
            y--;
            break;
        case 1:
            y--;
            break;
        case 2:
            x--;
            break;
        }
    }

    while(!sir.empty())
    {
        printf("%d ",sir.top());
        sir.pop();
    }

}
