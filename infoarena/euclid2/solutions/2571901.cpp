#include<bits/stdc++.h>
using namespace std;

int cmmdc(int a, int b){
    while(b){
        int aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
