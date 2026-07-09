//darius suge pula
//darius sa te uiti la comentarii
//darius suge pula
#include <fstream>
#include <bitset>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b;

int cmmdc(int a, int b)
{
    while (a!=b)
    {
        if (a>b) a=a-b;
        if (b>a) b=b-a;
    }
    return a;
}

int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
//darius sa citesti primele comentarii
