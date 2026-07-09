#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(int a, int b)
{
        while(b){
            int r = a % b;
            a = b;
            b = r;
        }
        g << a;
}
int n;
int main()
{
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        f >> x >> y;
        cmmdc(x, y);
        g << '\n';
    }

    f.close();
    g.close();
    return 0;
}
