#include <fstream>
using namespace std;

int gcf(int a, int b)
{
    if (a == 0) return b;
    else if (b == 0) return a;
    else return gcf((b%a), a);
}


int main()
{
    ofstream g("euclid2.out");
    ifstream f("euclid2.in");
    int a, b, T, i = 1;

    f >> T;
    for (; i <= T; i++)
    {
        f >> a >> b;
        g << gcf(a, b) << endl;
    }


    f.close();
    g.close();
    return 0;
}
