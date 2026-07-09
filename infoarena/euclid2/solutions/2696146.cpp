#include <fstream>
using namespace std;
int main()
{
    int d, a, b, n, i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(i = 1; i<=n;i++)
    {
        f >> a >> b;
        if(a == 1 || b == 1)
            d = 1;
        else if(a == 2 || b == 2)
            d = 2;
        else
        {
            while(a != b)
            {
                if(a > b)
                {
                    a = a - b;
                }
                else
                {
                    b = b - a;
                }
            }
            d = a;
        }
        g << d << "\n";
    }
    return 0;
}
