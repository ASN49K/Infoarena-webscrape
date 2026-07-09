#include <fstream>
using namespace std;
int a,b,r,n;
int main ()
{ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 while(n)
 {f>>a>>b;
 
 while(b)
 {r=a%b;
 a=b;
 b=r;}
 g<<a<<'\n';
 n--;}

 f.close(); g.close();
return 0;
}
