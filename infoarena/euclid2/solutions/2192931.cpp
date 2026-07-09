#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a;
    int x, y;
    f>>a;
    for(int i=1; i=a; i++)
    {
    f>>x>>y;
    while(x!=y)
    {
    if(x>y) x=x-y;
    else y=y-x;
    }
    g<<endl;
    }
    return 0;
}
