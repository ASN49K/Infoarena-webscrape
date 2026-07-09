/*
https://infoarena.ro/problema/euclid2
*/
#include <fstream>

using namespace std;

/*
int euclid(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return euclid(b, a % b);
}
*/

void euclid(int a, int b, int &d)
{
    if (b == 0)
    {
        d = a;
        return;
    }
    euclid(b, a % b, d);
}


int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t;
    in >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        in >> a >> b;
        //out << euclid(a, b) << "\n";
        int d;
        euclid(a, b, d);
        out << d << "\n";
    }
    in.close();
    out.close();
    return 0;
}
