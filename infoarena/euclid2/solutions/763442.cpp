#include <fstream>

using namespace std;

long Euclid( long a, long b)
{
    long r;
   while(b)
   {
      r=b;
      b=a%b;
	  a=r;
   }
   return a;
}

int main()
{
   int t;
   long a,b;
   
   ifstream cin("euclid2.in");
   ofstream cout("euclid2.out");
   cin >> t;
   while(t--)
   {
       cin >> a >> b;
       cout << Euclid(a,b) << endl;
   }
   
   cout.close();
   return 0;
}
