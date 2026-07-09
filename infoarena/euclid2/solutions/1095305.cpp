#include <iostream>

using namespace std;

int main()
{int a,b,r;
cin>>a;
cin>>b;
while(b>0)
{
    r=a%b;
    a=b;
    b=r;
}
if(a==1)
    cout<<"0";
    else
    cout<<a;
return 0;
}
