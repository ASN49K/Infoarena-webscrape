#include<cstdio>
int x,v,t,j;
int main ()
{
freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);
scanf("%d",&t);
while(t--)
    {
    scanf("%d",&v);
    scanf("%d",&x);
    while(v--)
        {
        scanf("%d",&j);
        x=x^j;
        }
    if(x==0)
        printf("NU\n");
    else
        printf("DA\n");
    }
return 0;
}
