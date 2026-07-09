#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int cmmdc(int a, int b)
{
    if (a % b == 0)
        return b;
    return cmmdc(b, a % b);
}

int main()
{
	int T, a, b;
    fi >> T;
    for (int i = 0; i < T; i++)
    {
        fi >> a >> b;
        fo << cmmdc(a, b) << '\n';
    }
    fi.close();
    fo.close();
	return 0;
}