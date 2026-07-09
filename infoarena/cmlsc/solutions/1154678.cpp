#include<cstdio>
#include<cmath>
using namespace std;
long long t,n,nrot,rez;
double nfix;

int main()
{
    freopen("chiftea.in","r",stdin);
    freopen("chiftea.out","w",stdout);
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        nfix=sqrt(n);
        nrot=(int)nfix;
        if(n==1) rez=4;
        else if(nrot==nfix) rez=4*(nrot+1)-4;
        else if(nrot+0.5>nfix) rez=4*(nrot+1)-2;
        else rez=4*(nrot+1);
        printf("%ld\n",rez);
    }

    return 0;
}
