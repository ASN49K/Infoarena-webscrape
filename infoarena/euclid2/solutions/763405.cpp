#include <fstream>

using namespace std;

long long Euclid(long long a,long long b)
{
   long long r;
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
   long long a,b;
   
   ifstream cin("euclid2.in");
   ofstream cout("euclid2.out");
   cin >> t;
   for(int i=0;i<t;i++)
   {
       cin >> a >> b;
       cout << Euclid(a,b) << endl;
   }
   cin.close();
   cout.close();
   return 0;
}
