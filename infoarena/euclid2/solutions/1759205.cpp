#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    long long unsigned c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int n;
    f>>n;
    for(int i=0;i<n;i++)
    {
        long long unsigned a,b;
        f>>a>>b;
        if(i!=n-1)
        g<<euclid(a,b)<<"\n";
        else
            g<<euclid(a,b);
    }
}
