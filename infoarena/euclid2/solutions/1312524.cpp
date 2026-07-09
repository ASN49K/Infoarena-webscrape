#include<cstdio>

using namespace std;

int cmmdc(int a, int b){
    int c;
    while(b!=0){
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main(){

    int a,b,c,t;

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);

    for(int i=1;i<=t;i++){

        scanf("%d %d\n",&a,&b);
        c=cmmdc(a,b);
        printf("%d\n",c);

    }

    return 0;
}
