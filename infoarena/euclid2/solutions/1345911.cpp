#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    if(a>b)
        if(a%b==0)
            return b;
        else
            return (b,a%b);
    else
        if(b%a==0)
            return a;
        else
            return (a,b%a);
}

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");

    int n,i,x,y;

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<endl;
    }

    f.close();
    g.close();
    return 0;
}
