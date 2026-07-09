#include <cstdio>

using namespace std;

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int a,b,r=1,n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        if(b>a){
            a=a+b;
            b=a-b;
            a=a-b;
        }
        r=1;
        while(r){
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d", a);
        printf("\n");
    }
    return 0;
}
