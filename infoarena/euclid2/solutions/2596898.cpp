#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int cmmdc(int a,int b)
{
int r=a%b;
while(r!=0)
{
a=b;
b=r;
r=a%b;
}
return b;
}

/**
  a < b => r = a
   a  b  r
  24 36 24
  36 24 12
  24 12  0

*/
int main()  {
int n,x,y;
cin>>n;
while(cin>>x>>y)
cout<<cmmdc(x,y)<<endl;
}
