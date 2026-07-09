//http://www.infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int &a, int &b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
   int a,b,t;
   in >> t;
   for(int i = 0; i < t ; i++)
   {
       in >> a >> b;
       out << cmmdc(a,b) << '\n';
   }
}
