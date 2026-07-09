#include <fstream>

using namespace std;
int main()
{
ifstream n("euclid2.in");
ofstream D("euclid2.out");

    int T,a,b,r,i;

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
n.close();
D.close();
return 0;
}
