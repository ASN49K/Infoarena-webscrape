#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int x,int y)
{
    int z;
    while (z!=0)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}


int main()
{
    int i,a,b,n;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a>>b;

    out<<cmmdc(a,b)<<"\n";

    }

in.close();
out.close();


return 0;
}
