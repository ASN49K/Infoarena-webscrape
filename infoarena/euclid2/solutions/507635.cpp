#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t, a, b, i, j;
int main()
{ f>>t;
  for(i=1; i<=t; i++) { f>>a>>b;
                        while(a!=b) if(a>b) a=a-b;
                                    else b=b-a;
                        if(a==b) g<<a<<"\n";
					  }
  f.close();
  g.close();
  return 0;
}  