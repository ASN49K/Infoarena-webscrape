#include <fstream>

using namespace std;

long Euclid(long a,long b)
{
   long r;
   while( (r=a%b)!=0)
   {
      a=b;
	  b=r;
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
  
   for(int i=0;i<t;i++)
   {
       cin >> a >> b;
       cout << Euclid(a,b) << endl;
   }
   cin.close();
   cout.close();
   return 0;
}
