#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int rest;
    while(b)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main()
{
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
