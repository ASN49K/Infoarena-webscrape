#include <fstream>

using namespace std;
int cmmdc(int a, int b)
 {
    while(a!=b)
    {
    if(a>b)a=a-b;
    else b=b-a;
    }
  return a;
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
