#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
    int temp;
    while(b)
        {
            temp=b;
            b=a%b;
            a=temp;
        }
    return a;
}

int main()
{
    int n,a,b;
    f>>n;
    while(n--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
