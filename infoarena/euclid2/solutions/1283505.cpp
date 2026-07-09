#include <cstdio>
using namespace std;
int euclid(int a, int b){
    int sol;
    if(b==0)return a;
    sol=euclid(b,a%b);
    return sol;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
