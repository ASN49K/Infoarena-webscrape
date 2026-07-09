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
        int a, b, divizor = 1;
        f>>a>>b;
        for(int j = 2; j <= min(a, b); j++)
        {
            if(a % j == 0 && b % j == 0)
                divizor = j;
        }
        g<<divizor<<'\n';
    }
    return 0;
}
