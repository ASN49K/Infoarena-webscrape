#include <iostream>
#include <fstream>
using namespace std;
int cmmdc (int a,int b)
{
   if(a%b==0)
      return b;
   else
      return cmmdc(b,a%b);
}



int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,a,b;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
     cin>>a>>b;
     cout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
