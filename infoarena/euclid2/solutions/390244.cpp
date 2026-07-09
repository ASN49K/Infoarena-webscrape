#include <fstream.h>
int main()
{
long n,a,b,r;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
f>>n;
while(n--)
     {
     f>>a>>b;
     while (b)
	   {
	   r=a%b;
	   a=b;
	   b=r;
	   }
     o<<a<<endl;
     }
return 0;
}