#include <fstream>

#define Y "DA"
#define N "NU"
#define in "nim.in"
#define out "nim.out"

std :: ifstream f(in);
std :: ofstream g(out);

class NIM
{
    protected :
        int T, P;

    public :
        void Compute();
};

void NIM :: Compute ()
{
    f >> T;

    int x;
    while (T --)    {
        f >> P >> x;

        for(int xx, i = 2; i <= P; ++i) {
            f >> xx;
            x ^= xx;
        }

        if(x)   g << Y << '\n';
        else    g << N << '\n';
    }
}

int main()
{
    NIM obj;

    obj.Compute();

    return 0;
}
