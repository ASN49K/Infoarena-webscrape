#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("eulcid2.out");
int main()
{
    int a,b,mx=0,i,ok=1,m,n;
    in>>a>>b;
    m=a;
    n=b;
    if(m>n)
      mx=n;
     if(m<n)
      mx=m;
    for(i=mx;i>=1;i-- && ok!=0)
    {
        if(a%i==0 && b%i==0) ok=0;
        if(ok==0)
        {out<<i;
            break;}

    }

    return 0;
}
