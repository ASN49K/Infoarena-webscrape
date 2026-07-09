#include <iostream>
#include <fstream>
using namespace std;
fstream f("euclid2.in");
fstream g("euclid2.out");
int main()

{
    int t,i,x,y;

    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        while((x!=0)&&(y!=0))
            if(x>y)
                x=x%y;
            else
                y=y%x;

        if(x!=0)
            g<<x<<'\n';
        else
            g<<y<<'\n';
    }
}
