#include <bits/stdc++.h>

using namespace std;

int t,a,b;
int cmmdc(int,int);
int main()
{
ios::sync_with_stdio(false);
#ifdef INFOARENA
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
#endif
#ifndef INFOARENA
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}

int cmmdc(int a,int b){
    while (b){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
