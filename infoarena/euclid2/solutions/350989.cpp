#include <fstream.h>
using namespace std;
long a,b,t;
int gcd(int a, int b) 
{if(!b) return a;
return gcd(b,a%b);

} 

int main()
{int i;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>t;
 for(i=1;i<=t;i++)
 {f>>a>>b;
 g<<gcd(a,b)<<endl;
}
 f.close();
 g.close();
 return 0;
}
