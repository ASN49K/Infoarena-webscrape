#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    int T{}, a{}, b{}, r{};
    fin >> T;
    for(int i = 0; i < T; ++i)
    {
        fin >> a >> b;
        while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
