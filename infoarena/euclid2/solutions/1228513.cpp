#include <fstream>

using namespace std;

int main()
{
   ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");
   int _;
   fin>>_;
   for(int __=0;__<_;__++)
   {
      int a,b;
      fin>>a>>b;
      int r;
      while(b!=0)
      {
	 r=a%b;
	 a=b;
	 b=r;
      }
      fout<<a<<"\n";
   }
   return 0;
}
