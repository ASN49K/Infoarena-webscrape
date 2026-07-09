#include <iostream>
#include <fstream>
using namespace std;
int a,b,t;
int cmmdc(int a,int b)
{
    if (a==b) return a;
      else if (a>b)  return cmmdc(a-b,b);
         else return cmmdc(a,b-a);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b);
    }
    f.close();
    g.close();
    return 0;
}
