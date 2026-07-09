#include<stdio.h>
#include<stdlib.h>

int euclid(int a, int b)
{
    int c=1;
    while(c!=0)
    {
               c=a%b;
               a=b;
               b=c;
               }
    return a;
    }
int main()
{
    int t,a[100001][2],c;
    freopen("euclid2.in","r",stdin);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
    fclose(stdin);
    freopen("euclid2.out","w",stdout);
    for(int i=1;i<=t;i++)
    {
            c=euclid(a[i][0],a[i][1]);
            printf("%d\n",c);
            }
    fclose(stdout);
    return 0;
    }
