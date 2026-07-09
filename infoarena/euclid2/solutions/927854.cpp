#include <fstream>
int euclid (int &a, int &b)
{
    return (a, a % b);
}
using namespace std;

int main()
{
    int T, a, b;
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    in >> T;
    for (;T ; --T)
    {
        in >> a >> b;
        out << euclid (a, b) <<'\n';
    }
    out.close ();
    in.close ();
    return 0;
}
