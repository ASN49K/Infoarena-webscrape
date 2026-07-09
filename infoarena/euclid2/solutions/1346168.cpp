#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if(!b)
        return a;
    else
    euclid(b,a%b);
}

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");

    int t,i,x,y;
    f>>t;
    while(t)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
        t--;
    }

    f.close();
    g.close();
    return 0;
}
