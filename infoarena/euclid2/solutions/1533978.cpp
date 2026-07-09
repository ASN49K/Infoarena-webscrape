#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,a,b,i;

int cmmdc(int x,int y);
void citire();

int main()
{
 citire();

 return 0;
}

void citire()
{
 f>>T;
 for(i=0;i<T;i++)
 {f>>a>>b;
  cmmdc(a,b);
 }

}

int cmmdc(int x, int y)
{int k;
 while(y)
   {
    k=x%y;
    x=y;
    y=k;
   }

 g<<a+b<<"\n";

}
