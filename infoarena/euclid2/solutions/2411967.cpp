#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int rest;
    while(b)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T, a, b;
    in >> T;
    for(int i = 1; i <= T; i++)
    {
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }
    in.close();
    out.close();
    return 0;
}
