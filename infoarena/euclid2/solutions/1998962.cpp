#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int a,b,r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return 0;
}
