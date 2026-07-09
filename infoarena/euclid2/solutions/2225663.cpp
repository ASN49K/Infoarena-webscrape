#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b, a % b);
}

int main()
{
    int T, A, B, i, c;

    f >> T;

    for(i = 0; i < T; i++)
    {
        f >> A >> B;
        g << cmmdc(A, B) << endl;
    }

    f.close();
    g.close();

    return 0;
}
