#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a1, int a2)
{
    while (a1 != a2)
    {
        if (a1>a2)
        {
            a1 = a1 - a2;
        }
        else
        {
            a2 = a2 - a1;
        }
    }
    return a1;
}

int main()
{
    int T;
    in >> T;
    while (T>0)
    {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << endl;
        T--;
    }
}
