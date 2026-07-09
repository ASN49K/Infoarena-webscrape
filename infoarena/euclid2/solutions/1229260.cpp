#include <iostream>

using namespace std;
int a,b,cmmdc(int a,int b),r,t;
int main()
{
   cin>>a>>b;
  { for( r=0;b;)
        r=a%b;
        a=b;
        b=r;
        return a;

  }
    t=cmmdc(a,b);
    cout<<t;
    return 0;
}


