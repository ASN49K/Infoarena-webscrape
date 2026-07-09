#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int m,n;
int a[1030],b[1030];
int matrix[1030][1030];
int sol[1030];
int di[3]= {0,-1,-1},dj[3] ={-1,0,-1};
void cit()
{
    scanf("%d %d",&m,&n);
    for(int i = 1 ; i <= m ; i++)
        scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",&b[i]);
}

void rezolv()
{
    for(int i = 1 ; i <=  n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(b[i] == a[j])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max(max(matrix[i-1][j],matrix[i-1][j-1]),matrix[i][j-1]);
        }
    }
}
void solutii(int &u)
{
    int i = n;
    int j = m;
    u = 0;
    while(matrix[i][j])
    {
        if(a[j] == b[i])
        {
            sol[u++] = b[i];
            i--;
            j--;
        }
        else
        {
            for(int k = 0 ; k < 3 ; k++)
            {
                int ii = i + di[k];
                int jj = j + dj[k];
                if(matrix[ii][jj] == matrix[i][j])
                {
                    i = ii;
                    j = jj;
                    break;
                }
            }
        }
    }
}
int main()
{
    int u = 0;
    freopen("clmsc.in","r",stdin);
    freopen("clmsc.out","w",stdout);
    cit();
    rezolv();
    printf("%d\n",matrix[n][m]);
    solutii(u);
    for( u-- ; u >= 0 ; u--)
        printf("%d ",sol[u]);
    return 0;
}
