#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int n;
int functie(int x, int y)
{
    int r = 1;
    while(r)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int a, b;
    in >> n;
    for(int i = 1; i <= n; i++)
    {
        in >> a >> b;
        out << functie(a,b) <<'\n';
    }

}
