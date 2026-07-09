#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long unsigned
#define pb push_back
#define mp make_pair

int gcd(int a, int b){
    int t;
    while(b){
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    int n,i,a,b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a, b));
    }
    return 0;
}
