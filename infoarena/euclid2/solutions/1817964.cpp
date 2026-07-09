#include <stdio.h>
using namespace std;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,c,n;
    scanf("%d",&n);
    while(n){
    scanf("%d%d",&a,&b);
        while(b){
        c=a%b;
        a=b;
        b=c;
        }
        printf("%d\n",a);
        n--;
    }
    return 0;
}
