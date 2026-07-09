#include <iostream>
#include <cstdio>
using namespace std;
int cmmdc(int a,int b){
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a,&b),cout<<cmmdc(a,b)<<endl;
    return 0;
}
