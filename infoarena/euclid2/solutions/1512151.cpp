#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream q("euclid2.out");

int cmmdc(int a, int b)
{
   if (b==0){return a;}
   return cmmdc(b,a%b);
}

int main()
{
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        q<<cmmdc(a,b)<<"\n";
    }
    f.close();
    q.close();
}
