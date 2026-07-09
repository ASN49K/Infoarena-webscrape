#include <fstream>

using namespace std;

int a, b;

int euclid(int a, int b)
{
    while(b!=0)
    {
        int c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>a>>a>>b;
    g<<euclid(a, b)<<"\n";
    while(f>>a>>b) g<<euclid(a,b)<<"\n";
    return 0;
}
