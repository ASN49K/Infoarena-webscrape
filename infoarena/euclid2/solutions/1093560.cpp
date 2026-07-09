#include<cstdio>
using namespace std;
int N,a,b;
inline int cmmdc(int a,int b)
{
    while (b!=0)
    {
        int aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
