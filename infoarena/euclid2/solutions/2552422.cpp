#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int div(int a, int b)
{
    if(!b)
        return a;
    return div(b, a%b);
}

int main()
{
    int a, b, n, c;
    in >> n;
    while (n)
    {
        in >> a >> b;
        out << div(a,b) << "\n";
        n--;
    }
}
