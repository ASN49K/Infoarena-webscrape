#include <fstream>
using namespace std;
int main ()
{
   long a,b,r,t;
   ifstream cin ("euclid.in");
   ofstream cout ("euclid.out");
  
   cin>>t;
   while (t)
{
   cin>>a>>b;
      while (b)
      {
	 r=a%b;
	 a=b;
	 b=r;
      }
   cout<<a<<"\n";
    t--; 
}
return 0;
}
