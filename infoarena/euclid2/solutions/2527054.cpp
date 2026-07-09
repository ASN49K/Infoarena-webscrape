#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int T;
    f>>T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
        f>>a>>b;
        while(b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        g<<a<<'\n';
    }
    return 0;
}
