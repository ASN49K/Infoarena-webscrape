#include <iostream>
#include <stdio.h>
#define NMax 1024
using namespace std;
short x[NMax],y[NMax],c[NMax][NMax],n,m,i,j;
short b[NMax][NMax];
void afis(int i, int j)
{
    if(i>=0&&j>=0)
        {
            if(b[i][j]==1)
                {

                    afis(i-1,j-1);
                    printf("%d ",x[i]);
                }
            else if(b[i][j]==2) afis(i-1,j);
            else afis(i,j-1);
        }
}
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d\n",&n,&m);
for(i=1;i<=n;i++)
    scanf("%d ",&x[i]);
for(i=1;i<=m;i++)
    scanf("%d ",&y[i]);
for(i=1;i<=n;i++)
    c[i][0]=0;
for(i=1;i<=m;i++)
    c[0][i]=0;

for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
        else
        {
            if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }
            else { c[i][j]=c[i][j-1]; b[i][j]=3; }
        }
printf("%d\n",c[n][m]);
afis(n,m);
fclose(stdin);
fclose(stdout);
return 0;
}
