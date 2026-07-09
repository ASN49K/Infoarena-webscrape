#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int eucl(int a, int b)
{
    if(b==0) return a;
    else eucl(b, a%b);
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
