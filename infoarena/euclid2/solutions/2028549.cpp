#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,a,b,r;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
     cin>>a>>b;
     while(b!=0)
     {
        r=a%b;
        a=b;
        b=r;
     }
     cout<<a<<endl;
    }
    return 0;
}
