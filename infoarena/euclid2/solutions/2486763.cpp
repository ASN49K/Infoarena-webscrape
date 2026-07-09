#include <bits/stdtr1c++.h>
using namespace std;

long long int cmmdc(long long int a,long long int b)
{
    long long int r;
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
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
