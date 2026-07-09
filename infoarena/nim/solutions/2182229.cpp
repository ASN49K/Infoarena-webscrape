#include<cstdio>
int main()
{
 freopen("nim.in","r",stdin);
 freopen("nim.out","w",stdout);
 int t;
 scanf("%d ",&t);
 for(int i=1;i<=t;i++)
    {
     int n;
     scanf("%d ",&n);
     int rez=0;
     for(int j=1;j<=n;j++)
        {
         int x;
         scanf("%d ",&x);
         rez=rez^x;
        }
     if(rez==0)
        printf("NU\n");
     else
        printf("DA\n");
    }
return 0;
}
