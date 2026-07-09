#include <fstream.h>
int main ()
{
   ifstream fin ("euclid2.in");
   ofstream fout ("euclid2.out");
   long a,b,r,t;
   fin>>t;
   while (t)
{
   fin>>a>>b;
      while (b)
      {
	 r=a%b;
	 a=b;
	 b=r;
      }
   fout<<a<<"\n";
    t--; 
}
return 0;
}