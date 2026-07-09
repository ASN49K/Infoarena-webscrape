#include <iostream>

using namespace std;
int a,b,n,i,cmmdc,r;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cmmdc=a;
        cout<<cmmdc<<endl;
    }
    return 0;
}
