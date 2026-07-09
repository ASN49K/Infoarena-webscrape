#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream q("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    do
    {
        r=a%b;
        a=b;
        b=r;
    }while(r!=0);
    return a;
}

int main()
{
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        q<<cmmdc(max(a,b),min(a,b))<<endl;
    }
    f.close();
    q.close();
}
