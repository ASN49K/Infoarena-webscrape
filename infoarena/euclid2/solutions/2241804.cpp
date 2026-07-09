#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int n;
int x,y;

int euclid(int a, int b)
{
    int r;
    r=a%b;
    while(r!=0)
    {
            a=b;
            b=r;
            r=a%b;
    }
    return b;

}

int main()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y);
        g<<"\n";
    }
    return 0;
}
