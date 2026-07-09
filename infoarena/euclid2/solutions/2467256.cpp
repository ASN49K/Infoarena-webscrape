#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
    while(b)
        b=a%b+(a=b)-b;
    return a;
}

int main()
{
    int a,b;
    f>>a>>b;
    g<<euclid(a,b);
    return 0;
}
