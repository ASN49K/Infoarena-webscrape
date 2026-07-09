#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n,a,b,i,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        while(a%b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",b);
    }

    return 0;
}
