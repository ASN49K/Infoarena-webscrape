#include <iostream>
using namespace std;
int cmmdc(int a,int b)
{
    int r;
    r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return(a);
}
int main()
{
    int t,i;
    int a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
