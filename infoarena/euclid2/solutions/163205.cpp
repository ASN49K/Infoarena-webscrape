#include<fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;

  int cmmdc(int a, int b)
  {
       if(b==0) return a;
       return cmmdc(b,a % b);
  }


  int main(void)
  {f>>t;
  for(t;t;t--)
  {f>>a>>b;
  g<<cmmdc(a,b)<<endl;
  }
  return (0);
  }