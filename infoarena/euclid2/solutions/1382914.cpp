#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int64_t t, x, y;
int64_t GCD(int64_t a, int64_t b)
{
	if(!b) return a;
	 else  return GCD(b,a%b);
}
int main()
 {
   f>>t;
   for (int i = 0; i < t; ++i)
   {
   	f>>x>>y;
   	g<<GCD(x,y)<<'\n';
   }
 	return 0;
 } 