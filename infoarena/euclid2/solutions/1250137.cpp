#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int tc;
    int a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
}
