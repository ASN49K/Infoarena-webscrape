#include<stdio.h>
using namespace std;

int n,a,b;

int cmd(int a,int b)
{
    if(!b)
      return a;
    else
        return cmd(b,a%b);
}


int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&n);

    for(; n; n--)
     {
         scanf("%d %d",&a,&b);
         printf("%d\n",cmd(a,b));
     }


     fclose(stdin);
     fclose(stdout);

     return 0;

}
