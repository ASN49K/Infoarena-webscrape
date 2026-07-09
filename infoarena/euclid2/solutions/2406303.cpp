#include <bits/stdc++.h>

using namespace std;

//ifstream fin("euclid2.in");
//ofstream fout("euclid2.out");

long gcd(long a,long b){
    if(b != 0){
        return gcd(b,a%b);
    }
    return a;
}

int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    long n,a,b,i,c;
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
