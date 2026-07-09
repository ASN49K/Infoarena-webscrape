#include <iostream>
#include <fstream>

using namespace std;

int subprog(int x,int y)
{
    if(x!=y)
    {
        if(x>y)
            return subprog(x-y,y);
        else
            if(x<y)
            return subprog(x,y-x);
    }

    return x;
}

int main()
{
    int T,i=1,a,b,x;

    fstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<subprog(a,b)<<"\n";

    }
    f.close();
    g.close();
    return 0;
}
