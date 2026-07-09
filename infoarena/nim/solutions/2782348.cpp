#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T, N;
int main()
{
    f >> T;
    for(int i = 1; i <= T; i++)
    {
        f >> N;
        int s = 0, x = 0;
        for(int j = 1; j <= N; j++)
        {
            f >> x;
            s ^= x;
        }
        if(s != 0) g << "DA\n";
        else g << "NU\n";
    }
    return 0;
}