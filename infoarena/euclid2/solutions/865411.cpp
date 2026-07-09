#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
void euclid(int a,int b)
{
    int r=1;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<"\n";
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        euclid(a,b);
    }
}
