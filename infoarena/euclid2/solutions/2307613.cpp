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
    int a, b, T;

    f >> T;
    for (int i = 1; i <= T; i++)
    {
        f >> a >> b;
        g << gcf(a, b) << endl;
    }


    f.close();
    g.close();
    return 0;
}
