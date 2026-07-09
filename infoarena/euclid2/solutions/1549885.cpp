#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
int main()
{
    f >> n;
    while (n)
    {
        int a,b;
        f >> a >> b;
        int r = a % b;
        while (r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        g << b <<"\n";
        n--;
    }
    return 0;
}
