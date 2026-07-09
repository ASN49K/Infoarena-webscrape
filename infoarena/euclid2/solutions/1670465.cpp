#include <iostream>

using namespace std;

int main()
{
    int a,b,mx=0,i,ok=1,m,n;
    cin>>a>>b;
    m=a;
    n=b;
    if(m>n)
      mx=n;
     if(m<n)
      mx=m;
    cout<<mx<<endl;
    for(i=mx;i>=1;i-- && ok!=0)
    {
        if(a%i==0 && b%i==0) ok=0;
        if(ok==0)
        {cout<<i;
            break;}

    }

    return 0;
}
