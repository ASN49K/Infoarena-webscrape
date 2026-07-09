#include<fstream>
#include <iostream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,a,b,i,r;
    cin>>T;
    for(i=1;i<=T;i++)
      {cin>>a>>b;
        while(b!=0)
             {r=a%b;
              a=b;
              b=r;}
       cout<<a<<"\n";}

return 0;
}
