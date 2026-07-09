#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
   int a,b,n;
   cin>>n;
  for(int i=1;i<=n;i++)
  { cin>>a>>b;
   while(a!=0 && b!=0)
   if(a>b)a=a%b;
   else b=b%a;
  if(a!=0)cout<<a<<"\n";else cout<<b<<"\n";
  }
   return 0;
}
