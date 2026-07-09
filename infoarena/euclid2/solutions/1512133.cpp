#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream q("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    r=a%b;
    a=b;
    b=r;
    while (r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return a;
}

int main()
{
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        q<<cmmdc(max(a,b),min(a,b))<<"\n";
    }
    f.close();
    q.close();
}
