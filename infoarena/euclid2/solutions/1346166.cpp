#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if(b==0)
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
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
    }

    f.close();
    g.close();
    return 0;
}
