#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int d(int a,int b)
{
int r=a%b;
while(r)
{
a=b;
b=r;
r=a%b;
}
return b;
}
int main()  {
  int a,b,t;
  cin >> t;
  for(int i=1;i<=t;i++)
  {
  cin>>a>>b;
  cout<<d(a,b)<<'\n';
  }
}
