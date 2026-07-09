#include <bits/stdtr1c++.h>
using namespace std;

int cmmdc(long long int a,long long int b)
{
    long long int r;
    if(a==0 or b==0)
        return a+b;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}

int main()
{
    int n,a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
