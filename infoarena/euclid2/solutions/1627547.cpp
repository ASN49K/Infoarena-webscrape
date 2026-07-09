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
    int n,i=1,a[100],x;

    fstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;
    for(i=1;i<=n*2;i++)
        f>>a[i];

    for(i=1;i<=n*2;i=i+2)
    {

        x=subprog(a[i],a[i+1]);
        g<<x<<"\n";
    }
    return 0;
}
