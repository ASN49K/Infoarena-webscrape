#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,x,y,r;

    in>>n;
    while(n--)
    {
        in>>x>>y;

        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        out<<x<<"\n";
    }

    return 0;
}
