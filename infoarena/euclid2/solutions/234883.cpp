#include <iostream.h>
#include <fstream.h>
fstream f("euclid2.in", ios::in);
fstream g("euclid2.out", ios::out);
int main()
{
 long a, b, t, i, r;
 f>>t; f.get();
 for (i=1;i<=t;i++){
  f>>a; f.get();
  f>>b; f.get();
  do{
     r=a%b;
     a=b;
     b=r;
     } while (r);
  if (a!=1) g<<a<<endl;
     else g<<'0';
		    }
  f.close();
  g.close();
  return 0;
}
