#include <fstream>

using namespace std;
ifstream f("euclid1.in");
ofstream g("euclid1.out");
int t,a,b;
int euclid(int a, int b)
{
    if (b==0) return a;
    else return euclid(b, a % b);
}
int main()
{
    f>>t;
    for (int i=0;i<t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
