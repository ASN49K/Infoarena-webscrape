#include <fstream>
#include <limits>

using namespace std;

int Euclid(int a,int b)
{
   int r;
   while( r = a%b )
   {
      a=b;
	  b=r;
   }
   return b;
}

int main()
{
   int t;
   int a,b;
   
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
