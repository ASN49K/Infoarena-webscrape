#include<stdio.h>
using namespace std;

int n;
int a,b;

int gcd(int a,int b)
{
    if(b==0) return a;
    else
     return gcd(b,a%b);
}

void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    read();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
