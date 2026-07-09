#include <fstream>
#include <limits>

using namespace std;

long Euclid(long a,long b)
{
   long r=a%b;
   while( r )
   {
      a=b;
	  b=r;
	  r=a%b;
   }
   return b;
}

int main()
{
   int t;
   long a,b;
   
   ifstream cin("euclid2.in");
   ofstream cout("euclid2.out");
   cin >> t;
  // cout << numeric_limits<int>::max() << endl;
   
   for(int i=0;i<t;i++)
   {
       cin >> a >> b;
       cout << Euclid(a,b) << endl;
   }
   cin.close();
   cout.close();
   return 0;
}
