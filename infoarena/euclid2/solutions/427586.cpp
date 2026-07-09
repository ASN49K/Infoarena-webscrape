#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

void open(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
}
int t,a,b;
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(){
    open();
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
