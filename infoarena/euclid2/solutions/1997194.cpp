#include <iostream>
#include <cstdio>
using namespace std;

int a,b,r,T;

int main(){

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&a,&b);
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n",a);
    }

    return 0;
}
