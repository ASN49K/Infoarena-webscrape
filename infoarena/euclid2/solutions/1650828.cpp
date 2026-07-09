#include <fstream>
using namespace std;

int T, a ,b;

int cmmdc (int a, int b)
{
    if(b==0)return a;
    //if(b==0)return a;
    //if(a>b)
        return cmmdc(b,a%b);
    //else return cmmdc(a,b%a);
}


int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(int i=1; i<=T; i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<"\n";
}
g.close();
f.close();
return 0;
}
