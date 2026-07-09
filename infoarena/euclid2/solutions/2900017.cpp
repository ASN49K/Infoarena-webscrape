#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(unsigned long int x, unsigned long int y)
{
    if(y == 0) return x;
    return euclid(y, x % y);

}
int main()
{
    unsigned long int t, a, b;
    f >> t;
    while(t)
    {
        f >> a >> b;
        g << euclid(a,b) << endl;
        t--;
    }
    return 0;
}
