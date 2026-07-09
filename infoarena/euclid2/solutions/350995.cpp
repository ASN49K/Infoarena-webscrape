#include <fstream.h>
using namespace std;
long a,b,t;
int main()
{int i,c;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>t;
 for(i=1;i<=t;i++)
 {f>>a>>b;
 while(b!=0)
 {c=a%b;
  a=b;
  b=c;
 }
 g<<a<<" ";
}
 f.close();
 g.close();
 return 0;
}
