#include <iostream>

using namespace std;
int n,i,a,b,r,v[1001];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        r=0;
        cin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        v[i]=a;

    }
    for(i=1;i<=n;i++)
        cout<<v[i]<<endl;
    return 0;
}
