#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int  x,y , t;
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
    for(;t ;--t)
    {
        f>>x>>y;
        g<<euclid(x, y);
        g<<endl;
    }

    f.close();
    g.close();
    return 0;
}
