#include <iostream>
using namespace std;
int main()
{
    int a,b,c,r,t;
    cin>>t;
    if(t<=100000&&t>=1)
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    return 0;
}
