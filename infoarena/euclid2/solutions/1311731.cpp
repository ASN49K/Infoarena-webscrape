#include <fstream>
#include<algorithm>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int euclid(int a,int b)
{
    if(b == 0)
        return a;
    else return euclid(b, a % b);
}
int main()
{
    int n,a,b;
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
