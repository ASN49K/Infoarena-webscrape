#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    int n, t1, t2, a, b, c;
    in >> n;
    ofstream out("euclid2.out");
    for (;n;--n)
    {
        in >> a >> b;
        while(b)
        {
            c = a;
            a = b;
            b = c%b;
        }
        out << b;
    }
    return 0;
}
