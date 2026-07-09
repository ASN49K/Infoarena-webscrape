#include <fstream>

using namespace std;
int cmmdc(int a, int b)
 {
    if(b) return cmmdc(b,a%b);
    else return a;
 }
int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=0;i<t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
  f.close();
  g.close();
  return 0;
}
