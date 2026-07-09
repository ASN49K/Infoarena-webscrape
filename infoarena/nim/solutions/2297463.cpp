#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,a;
int main()
{
   f>>t;
   for(;t;t--){
      f>>n;
      x=0;
      for(;n;n--){
            f>>a;
            x^=a;}
      if(x)
      g<<"DA\n";
      else g<<"NU\n";
   }
}
