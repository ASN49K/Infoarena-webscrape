#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int eucl(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int a, b, c, d;
    f>>d;
    for(int i=1; i<=d; i++)
    {
    f>>a>>b;
    c=eucl(a, b);
    g<<c<<endl;
    }
    return 0;
}
