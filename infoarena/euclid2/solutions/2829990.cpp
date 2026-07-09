#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
int cmmdc(int x,int y)
{
    if(y==0)
        return x;
    else
    {
        while(y)
        {
            int r = x%y;
            x = y;
            y = r;
        }

        return x;
    }
}
int main()
{
        f>>t;

        for(int i = 1; i <= t; i++)
        {
            int x,y;
            f>>x>>y;
            g<<cmmdc(x,y)<<"\n";
        }

    return 0;
}
