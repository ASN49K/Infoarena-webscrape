#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int T,a,b,r,i;

ifstream n("euclid2.in");
ofstream D("euclid2.out");
n >> T;
for(i=1;i<=T;i++)
    {
    n >> a >> b;

 while(b)
    {
        r=a%b;
        a=b;
        b=r;

    }
        D << a << endl;
    }

return 0;
}
