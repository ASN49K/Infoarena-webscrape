#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int T, N, x, S;
    f >> T;
    while(T--)
    {
        f >> N;
        S = 0;
        while(N--)
        {
            f >> x;
            S ^= x;
        }
        g << (S != 0 ? "DA\n" : "NU\n");
    }
    f.close();
    g.close();
    return 0;
}
