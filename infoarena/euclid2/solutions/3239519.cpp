#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a,b,d,t;

int cmmdc(int a,int b){
    while(b){
        d=a%b;
        a=b;
        b=d;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>t;
    for(;t--;) {
       cin>>a>>b;
       cout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
