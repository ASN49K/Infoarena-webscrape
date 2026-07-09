#include<fstream.h>
unsigned long long r,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
f>>a>>b;
r=a%b;
while(r)
 {
  a=b;
  b=r;
  r=a%b;
 }
 
 f.close();
 g.close();
 return 0;
}
