#include <fstream>

using namespace std;

 int t;
   long a,b;
   
long Euclid()
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
  
   
   ifstream cin("euclid2.in");
   ofstream cout("euclid2.out");
   cin >> t;
   while(t--)
   {
       cin >> a >> b;
       cout << Euclid() << endl;
   }
   
   cout.close();
   return 0;
}
