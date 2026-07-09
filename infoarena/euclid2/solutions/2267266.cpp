
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long int x,a,b,r;
int main()
{
  in>>x;
while (x)
{
    x--;
    in>>a>>b;
    r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    out<<b<<endl;
}
    return 0;
}
