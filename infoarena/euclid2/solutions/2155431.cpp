#include <fstream>

using namespace std;

int cmmdc(int x, int y)
{
    if(y!=0) return cmmdc(y, x%y);
    return x;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    f>>n;
    for(int i=0, a, b; i<n; i++)
    {
        f>>a>>b;
        g<<cmmdc(a, b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
