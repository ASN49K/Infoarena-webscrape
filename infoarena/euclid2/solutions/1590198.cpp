#include<fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
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
