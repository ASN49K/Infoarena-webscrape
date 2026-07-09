#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int  a, b, t;
int euclid(int a, int b)
{
    if(b==0)
        return a;
    else
        return euclid(b, a%b);
}
int main()
{
    f>>t;
    for(;t ;t--)
    {
        f>>a>>b;
        g<<euclid(a, b);
    }

    f.close();
    g.close();
    return 0;
}
