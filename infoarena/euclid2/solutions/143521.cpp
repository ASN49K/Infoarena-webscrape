#include <fstream.h>
int main ()
{
   ifstream fin ("euclid2.in");
   ofstream fout ("euclid2.out");
   long a,b,r;
   fin>>a>>b;
      while (b)
      {
	 r=a%b;
	 a=b;
	 b=r;
      }
   fout<<a<<"\n";
return 0;
}
