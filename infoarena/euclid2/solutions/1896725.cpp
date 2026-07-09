#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,x,y,r;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>a>>b;
        x=a;y=b;
        while(y)
        {
            r=x%y;
            x=y;
            y=r;
        }
        g<<x<<endl;
    }
    return 0;
}
