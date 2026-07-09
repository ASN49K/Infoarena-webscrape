#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int x;
    int a,b,r;
    f >> x;
    for(int i=1 ;i<=x ;i++)
    {
         f >> a >> b;
    while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
    g<<a<<" ";
    g<<endl;

    }
    f.close();
    g.close();
    return 0;
}
