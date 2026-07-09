#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int T;
    int a,b,r;
    f >> T;
    for(int i=1;i<=T;i++)
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
