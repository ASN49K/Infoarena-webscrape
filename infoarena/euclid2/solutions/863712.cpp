#include<iostream>
#include<stdio.h>
using namespace std;
int a,b,c,T,i;
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
    cin>>T;
    for(i=1;i<=T;++i)
    {
        cin>>a>>b;
        if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
        while(b!=0)
        {
            c=a;
            a=b;
            b=c%a;
        }
        cout<<a<<"\n";
    }
    return 0;
}
