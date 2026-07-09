#include<stdio.h>

int euclid(int a, int b)
{
    if(!b) return a;
        else return euclid(b,a%b);
}


int main()
{
    int n;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);


while(n)
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",euclid(x,y));
    n--;
}
    return 0;
}
