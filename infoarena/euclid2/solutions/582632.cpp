#include <cstdio>
using namespace std;
int a,b,t;

int cmmdc(int x,int y)
{
    if(!y) return x;
    else return cmmdc(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
        --t;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
