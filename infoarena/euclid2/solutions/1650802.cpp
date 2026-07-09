#include <fstream>
using namespace std;

int T, a ,b;

int cmmdc (int a, int b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(a>b) return cmmdc(a-(a/b)*b,b);
    else cmmdc(a,b-(b/a)*a);
}


int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(int i=1; i<=T; i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<endl;
}
g.close();
f.close();
}
